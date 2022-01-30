#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# include "./constants.h"
# include "./libft/libft.h"
# include "./error/error.h"
# include "./shell/shell.h"
# include "./env/env.h"
# include "./redirect/redirect.h"
# include "./parsing/parsing.h"
# include "./builtin/builtin.h"

char	*get_next_line(int fd);
int		pipex(t_shell *shell);

#endif