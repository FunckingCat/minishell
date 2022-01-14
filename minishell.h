#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>

char	*get_next_line(int fd);
int		pipex(int argc, char **argv, char **envp);

#endif