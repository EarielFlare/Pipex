/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgregory <cgregory@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 17:40:29 by cgregory          #+#    #+#             */
/*   Updated: 2022/03/21 13:40:34 by cgregory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	main_cycle(t_pipex pipex, char *argv[], char *envp[])
{
	pipex.count = 0;
	while (pipex.count < pipex.cmd_nmbs)
	{
		if (pipex.count + 1 < pipex.cmd_nmbs
			&& pipe(pipex.tube[pipex.count % 2]) < 0)
			msg_perr(ERR_PIPE);
		pipex.pid[pipex.count % 2] = fork();
		if (pipex.pid[pipex.count % 2] == 0)
			child(pipex, argv, envp);
		if (pipex.count > 0)
		{
			close_pipes(&pipex);
			waitpid(pipex.pid[-(pipex.count % 2) + 1], NULL, 0);
		}
		pipex.count++;
	}
	waitpid(-1, NULL, 0);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	pipex;

	if (argc < args_in(argv[1], &pipex))
		msg_self(ERR_INPUT);
	get_infile(argv, &pipex);
	get_outfile(argv[argc - 1], &pipex);
	pipex.cmd_nmbs = argc - 3 - pipex.here_doc;
	pipex.paths = find_path(envp);
	pipex.cmd_paths = ft_split(pipex.paths, ':');
	if (!pipex.cmd_paths)
		pipe_free(&pipex);
	main_cycle(pipex, argv, envp);
	parent_free(&pipex);
	return (0);
}
