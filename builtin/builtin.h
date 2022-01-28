#ifndef BUILTIN_H
# define BUILTIN_H

# include "../env/env.h"
# include "../constants.h"

int	env(t_env *envi);
int	unset( t_env *envi, char *name);
int	export(t_env *envi, char *str);
int	pwd(t_env *envi);


#endif