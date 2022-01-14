/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unix <unix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 10:47:27 by tyamcha           #+#    #+#             */
/*   Updated: 2022/01/14 12:25:17 by unix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/wait.h>
# include "../libft/libft.h"

typedef struct s_command
{
	char	*arg;
	int		in;
	int		out;
}	t_command;

typedef struct s_env
{
	int			cmds;
	t_command	*commands;
	char		**ep;
	pid_t		*pids;
	char		*doc;
}	t_env;

t_env	*make_env(int argc, char **argv, char **envp);

char	*get_next_line(int fd);
void	error(char *name, char *desc);
void	fork_proc(t_env *env);

#endif