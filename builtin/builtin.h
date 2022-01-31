#ifndef BUILTIN_H
# define BUILTIN_H

# include "../env/env.h"
# include "../constants.h"

int	env(t_env *envi);
int	unset( t_env *envi, char *name);
int	export(t_env *envi, char *str);
int	pwd(t_env *envi);
int cd(char *arg, t_env *envi);
int echo(char *str);

int is_builtin(char *name);
void manage_builtin(char *name, char *arg, t_env *envi);

void	clean_split(char **new_var);
void check_args(char *extra);

#endif