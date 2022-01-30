#include "builtin.h"

int	pwd(t_env *envi)
{
	if (!envi || !envi->vars)
		return (1);
	ft_putstr_fd(env_get("PWD", envi), 1);
	write (1, "\n", 1);
	return (0);
}