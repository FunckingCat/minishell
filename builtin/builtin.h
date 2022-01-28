#ifndef BUILTIN_H
# define BUILTIN_H

# include "../env/env.h"

# define EXP "Export"
# define EXP_PAR "error with parameters"

int	env(t_env *envi);
int	unset( t_env *envi, char *name);
int	export(t_env *envi, char *str);
int	pwd(t_env *envi);
int cd(char *arg, t_env *envi);


#endif