#ifndef ERROR_H
# define ERROR_H

# include "../constants.h"
# include "stdio.h"

int		put_error(char *module, char *text);
void	*put_error_null(char *module, char *text);

#endif