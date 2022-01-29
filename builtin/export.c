#include "builtin.h"

void	clean_split(char **new_var)
{
	int	i;

	i = 0;
	while (new_var[i])
	{
		free(new_var[i]);
		i++;
	}
	free(new_var);
}

int	setting_element(t_env *envi, char *str)
{
	char *new;
	char **extra;

	new = ft_strchr(str, '=');
	extra = ft_split(str, '=');
	if (!extra || !extra[0])
		return (1);
	if (new)
		new = ft_strdup(&new[1]);
	else
	{
		clean_split(extra);
		return (env_set(extra[0], "", envi));
	}
	if (env_set(extra[0], new, envi) == 1)
	{
		clean_split(extra);
		return (1);
	}
	clean_split(extra);
	return (0);
}

int	set_good_elem(t_env *envi, char **new, int i)
{
	if (new[i][0] == '=')
	{
		clean_split(new);
		return (put_error(EXP, EXP_NOT_VALID));
	}
	else
	{
		if (setting_element(envi, new[i]))
		{
			clean_split(new);
			return (1);
		}
		else
		{
			clean_split(new);
			return (0);
		}
	}
}


int separating(t_env *envi, char *str)
{
	char **new;
	int i;

	i = 0;
	if (ft_strchr(str, '=') == NULL)
		return (0);
	new = ft_split(str, ' ');
	while (new && new[i])
	{
		if (ft_strchr(new[i], '=') != NULL)
		{
			return (set_good_elem(envi, new, i));
		}
		else
			i++;
	}
	clean_split(new);
	return (0);
}

int	export(t_env *envi, char *str)
{
	if (!str)
		return (1);
	return (separating(envi, str));
}
