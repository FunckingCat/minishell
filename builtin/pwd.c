#include "builtin.h"

int	pwd(t_env *envi)
{
	char *new;

	if (!envi || !envi->vars)
		return (1);
	new = env_get("PWD", envi);
	ft_putstr_fd(new, 1);
	write (1, "\n", 1);
	if (new)
		free(new);
	return (0);
}