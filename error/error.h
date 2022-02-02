#ifndef ERROR_H
# define ERROR_H

# include "../libft/libft.h"
# include "../constants.h"
# include "stdio.h"

int		put_error(char *module, char *text);
void	*put_error_null(char *module, char *text);
int		put_error_status(char *module, char *text, int st);
int		put_error_exit(char *module, char *text,  int st);

int		put_ext_error(char *module, char *obj, char *text);
int		put_ext_error_status(char *module, char *obj, char *text, int st);
void	*put_ext_error_null(char *module, char *obj, char *text);
int		put_ext_error_exit(char *module, char *obj, char *text,  int st);

#endif