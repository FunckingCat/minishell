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
		{
			free(extra[j]);
			j++;
		}
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
	{
		put_error(ENV, ENV_NO_PAR);
		return (1);
	}
	if (env_contain(name, envi))
	{
		extra = envi->vars;
		envi->vars = malloc(sizeof(char *) * (envi->length));
		if (!envi->vars)
			return (malloc_return_int());
		exclude_var(envi, name, extra);
		free(extra);
	}
	return (0);
}
