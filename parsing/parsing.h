#ifndef PARSING_H
#define PARSING_H

#include "../minishell.h"

# define Q_NCL			"quotes are not closed"
# define SYNTAX_PIPE	"syntax error near unexpected token '|'"

int	parse_pipes(t_shell *shell, char *cmd);

#endif