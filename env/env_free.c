#include "env.h"

t_env *env_free(t_env *envi)
{
	int	i;

	i = 0;
	if (!envi)
	{
		put_error(ENV, ENV_NO_PAR);
		return (NULL);
	}
	while (i < envi->length && envi->vars)
	{
		free(envi->vars[i]);
		i++;
	}
	if (envi->vars)
		free(envi->vars);
	free(envi);
	return (NULL);
}