#include "builtin.h"

int	env(t_env *envi)
{
	int	i;

	i = 0;
	if (!envi || !envi->vars)
		return (1);
	while (i < envi->length)
	{
		ft_putstr_fd(envi->vars[i], 1);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
