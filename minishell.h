#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "./libft/libft.h"
# include "./redirect/redirect.h"
# include "./error/error.h"
# include "./env/env.h"
# include "./builtin/builtin.h"
# include "constants.h"

char	*get_next_line(int fd);
int		pipex(int argc, char **argv, char **envp);

typedef struct s_shell
{
	int		cmds;
	char	**cmds_arr;
}	t_shell;

# include "./libft/libft.h"
# include "redirect/redirect.h"
# include "./parsing/parsing.h"

#endif