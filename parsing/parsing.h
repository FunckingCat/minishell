#ifndef PARSING_H
#define PARSING_H

# include "../libft/libft.h"
# include "../constants.h"
# include "../shell.h"
# include "../error/error.h"

# define RCH 13

char	**parse_pipes(char *cmd);

#endif