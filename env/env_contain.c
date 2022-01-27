#include "env.h"

int	is_contain(char *name, t_env *envi)
{
	int	i;

	i = 0;
	if (!name || !envi || !envi->vars)
	{
		put_error(ENV, ENV_NO_PAR);
		return (1);
	}
	while (i < envi->length)
	{
		if (ft_strncmp(envi->vars[i], name, ft_strlen(name)) == 0)
			return (1);
		i++;
	}
	return (0);
}