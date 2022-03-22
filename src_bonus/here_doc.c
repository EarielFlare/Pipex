/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgregory <cgregory@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 17:40:22 by cgregory          #+#    #+#             */
/*   Updated: 2022/03/21 17:02:34 by cgregory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	args_in(char *arg, t_pipex *pipex)
{
	if (arg && !ft_strncmp("here_doc", arg, 9))
	{
		pipex->here_doc = 1;
		return (6);
	}
	else
	{
		pipex->here_doc = 0;
		return (5);
	}
}

void	here_doc(char *argv)
{
	int		file;
	char	*buf;
	int		rd;

	file = open(".heredoc_tmp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (file < 0)
		msg_perr(ERR_HEREDOC);
	while (1)
	{
		write(1, "heredoc> ", 9);
		rd = get_next_line(&buf);
		if (rd < 0)
			exit(1);
		if (!ft_strncmp(argv, buf, ft_strlen(argv) + 1))
			break ;
		write(file, buf, ft_strlen(buf));
		write(file, "\n", 1);
		if (rd == 0)
		{
			write(1, "\n", 1);
			break ;
		}
	}
	close(file);
}
