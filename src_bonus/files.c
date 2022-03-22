/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgregory <cgregory@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 17:39:55 by cgregory          #+#    #+#             */
/*   Updated: 2022/03/21 17:03:01 by cgregory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*find_path(char **envp)
{
	while (*envp != NULL && ft_strncmp("PATH", *envp, 4))
		envp++;
	if (*envp == NULL)
		msg_self(ERR_ENVP);
	return (*envp + 5);
}

void	get_infile(char **argv, t_pipex *pipex)
{
	if (!ft_strncmp("here_doc", argv[1], 9))
	{
		here_doc(argv[2]);
		pipex->infile = open(".heredoc_tmp", O_RDONLY);
		if (pipex->infile < 0)
		{
			unlink(".heredoc_tmp");
			msg_perr(ERR_HEREDOC);
		}
	}	
	else
	{
		pipex->infile = open(argv[1], O_RDONLY);
		if (pipex->infile < 0)
			msg_perr(ERR_INFILE);
	}
}

void	get_outfile(char *argv, t_pipex *pipex)
{
	if (pipex->here_doc)
		pipex->outfile = open(argv, O_CREAT | O_WRONLY | O_APPEND, 0644);
	else
		pipex->outfile = open(argv, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (pipex->outfile < 0)
		msg_perr(ERR_OUTFILE);
}
