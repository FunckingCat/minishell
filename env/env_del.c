#include "env.h"

void	exclude_var(t_env *envi, char *name, char **extra)
{
	int		i;
	int		j;
	char	*old;

	i = 0;
	j = 0;
	while (j < envi->length)
	{
		if (ft_strncmp(extra[j], name, ft_strlen(name)) == 0)
			j++;
		else
		{
			envi->vars[i] = extra[j];
			i++;
			j++;
		}
	}
	envi->vars[i] = NULL;
	envi->length--;
}

int	env_delete(char *name, t_env *envi)
{
	char	**extra;

	if (!envi || !name || !envi->vars)
		return (put_error(ENV, ENV_MALLOC));
	if (env_contain(name, envi))
	{
		extra = envi->vars;
		envi->vars = ft_malloc(sizeof(char *) * (envi->length));
		if (!envi->vars)
			return (put_error(ENV, ENV_MALLOC));
		exclude_var(envi, name, extra);
	}
	return (0);
}
