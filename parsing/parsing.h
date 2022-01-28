#ifndef PARSING_H
#define PARSING_H

# include "../libft/libft.h"
# include "../constants.h"
# include "../shell.h"
# include "../error/error.h"

int		parse_pipes(t_shell *shell, char *cmd);

char	**split_to_commands(char *cmd, int cmds, int i, int j);

#endif