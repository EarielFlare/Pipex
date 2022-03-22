/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgregory <cgregory@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 17:39:18 by cgregory          #+#    #+#             */
/*   Updated: 2022/03/21 17:02:44 by cgregory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
# include "../libft/libft.h"
//	write, read, close, access
//	pipe, dup, dup2, execve, fork
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
//	malloc, free, exit
# include <stdlib.h>
//	open, unlink
# include <fcntl.h>
//	waitpid, wait
# include <sys/wait.h>
//	strerror
# include <string.h>
//	to perror
# include <stdio.h>

# define ERR_INFILE "Infile"
# define ERR_OUTFILE "Outfile"
# define ERR_CMD "Command not found: "
# define ERR_HEREDOC "Here_doc"
# define ERR_PIPE "Pipe"
# define ERR_ENVP "Environment error"
# define ERR_INPUT "Invalid number of arguments"

typedef struct s_pipex
{
	int		infile;
	int		outfile;
	char	*env_path;
	char	**cmd_paths;
	char	*cmd;
	char	**cmd_args;
	int		here_doc;
	pid_t	pid[2];
	int		cmd_nmbs;
	int		count;
	int		pipe_nmbs;
	int		idx;
	int		tube[2][2];
	char	*paths;
}			t_pipex;

int		get_next_line(char **line);
void	main_cycle(t_pipex pipex, char *argv[], char *envp[]);
//	childs.c
void	child(t_pipex pipex, char *argv[], char *envp[]);
//	free.c
void	close_pipes(t_pipex *pipex);
void	parent_free(t_pipex *pipex);
void	child_free(t_pipex *pipex);
void	pipe_free(t_pipex *pipex);
//	error.c
void	msg_pipe(char *arg);
void	msg_self(char *err);
void	msg_perr(char *err);
//	functions
char	*find_path(char **envp);
void	get_infile(char **argv, t_pipex *pipex);
void	get_outfile(char *argv, t_pipex *pipex);
//	here_doc.c
int		args_in(char *arg, t_pipex *pipex);
void	here_doc(char *argv);
#endif
