#include "env.h"

int	fill_new_vars(t_env *envi, char *str, char **extra)
{
	int	i;

	i = 0;
	envi->vars = ft_malloc(sizeof(char *) * (envi->length + 2));
	if (!envi->vars)
		return (1);
	while (i < envi->length)
	{
		envi->vars[i] = extra[i];
		i++;
	}
	envi->vars[i] = str;
	envi->vars[++i] = NULL;
	return (0);
}

void	env_reset(t_env *envi, char *name, char *str)
{
	int		i;
	char	*old;

	i = 0;
	while (i < envi->length)
	{
		if (ft_strncmp(envi->vars[i], name, ft_strlen(name)) == 0
				&& envi->vars[i][ft_strlen(name)] == '=')
		{
			old = envi->vars[i];
			envi->vars[i] = str;
		}
		i++;
	}
}

int	env_set(char *name, char *content, t_env *envi)
{
	char	**extra;
	char	*str;
	char	*str1;

	if (!name || !envi || !envi->vars)
		return(put_error(ENV, ENV_NO_PAR));
	str1 = ft_strjoin(name, "=");
	str = ft_strjoin(str1, content);
	if (env_contain(name, envi) == 0)
	{
		extra = envi->vars;
		if (fill_new_vars(envi, str, extra) == 1)
			return (put_error(ENV, ENV_MALLOC));
		envi->length++;
	}
	else
		env_reset(envi, name, str);
	return (0);
}
