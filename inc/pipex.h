/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgregory <cgregory@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 17:39:27 by cgregory          #+#    #+#             */
/*   Updated: 2022/03/21 14:07:27 by cgregory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
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
# define ERR_PIPE "Pipe"
# define ERR_ENVP "Environment error"
# define ERR_INPUT "Invalid number of arguments"

typedef struct s_pipex
{
	pid_t	pid1;
	pid_t	pid2;
	int		tube[2];
	int		infile;
	int		outfile;
	char	*paths;
	char	**cmd_paths;
	char	**cmd_args;
	char	*cmd;
}			t_pipex;

//	childs.c
void	first_child(t_pipex pipex, char *argv[], char *envp[]);
void	second_child(t_pipex pipex, char *argv[], char *envp[]);
//	free.c
void	parent_free(t_pipex *pipex);
void	child_free(t_pipex *pipex);
//	error.c
void	msg_pipe(char *arg);
void	msg_self(char *err);
void	msg_perr(char *err);
//	functions
char	*find_path(char **envp);
#endif
