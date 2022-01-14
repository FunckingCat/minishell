#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include </usr/include/readline/readline.h>
#include </usr/include/readline/history.h>
#include <stdlib.h>

char	*get_next_line(int fd);
int		pipex(int argc, char **argv, char **envp);

int		put_error(char *module, char *text);

# define PROMPT	"MINISHELL > "

# define RED	"\001\033[0;31m\002"
# define GREEN	"\001\033[0;32m\002"
# define YELLOW	"\001\033[0;33m\002"
# define BLUE	"\001\033[0;34m\002"
# define PURPLE	"\001\033[0;35m\002"
# define NONE	"\001\033[0m\002"

#endif