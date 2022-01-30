#include "env.h"

int	env_contain(char *name, t_env *envi)
{
	int	i;

	i = 0;
	if (!name || !envi || !envi->vars)
	{
		put_error(ENV, ENV_NO_PAR);
		return (-1);
	}
	while (i < envi->length && envi->vars[i])
	{
		if (ft_strncmp(envi->vars[i], name, ft_strlen(name)) == 0
			&& envi->vars[i][ft_strlen(name)] == '=')
			return (1);
		i++;
	}
	return (0);
}
