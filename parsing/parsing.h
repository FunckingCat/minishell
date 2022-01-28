#ifndef PARSING_H
#define PARSING_H

# include "../libft/libft.h"
# include "../constants.h"
# include "../shell.h"
# include "../error/error.h"

# define RCH 13

int		parse_pipes(t_shell *shell, char *cmd);

#endif