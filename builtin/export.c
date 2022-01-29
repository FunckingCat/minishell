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


int check_name(char **extra)
{
	int i;

	i = 0;
	if (!extra || !extra[0])
		return (1);
	while (extra[0][i] != '\0')
	{
		if ((extra[0][0] > 47 && extra[0][0] < 58)
			|| (!(extra[0][i] > 47 && extra[0][i] < 58)
			&& !(extra[0][i] > 64 && extra[0][i] < 91)
			&& !(extra[0][i] > 96 && extra[0][i] < 123)
			&& extra[0][i] != '_'))
		{
			clean_split(extra);
			put_error(EXP, EXP_NOT_VALID);
			return (1);
		}
		i++;
	}
	return (0);
}

int	setting_element(t_env *envi, char *str)
{
	char *new;
	char **extra;

	new = ft_strchr(str, '=');
	extra = ft_split(str, '=');
	if (check_name(extra) == 1)
		return (0);
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
		put_error(EXP, EXP_NOT_VALID);
		return (0);
	}
	else
	{
		if (setting_element(envi, new[i]))
		{
			clean_split(new);
			return (1);
		}
		else
			return (0);
	}
}

int	export(t_env *envi, char *str)
{
	char **new;
	int i;

	i = 0;
	if (!str)
		return (1);
	if (ft_strchr(str, '=') == NULL)
	{
		check_args(str);
		return (0);
	}
	new = ft_split(str, ' ');
	while (new && new[i])
	{
		if (ft_strchr(new[i], '=') != NULL)
		{
			if (set_good_elem(envi, new, i) == 1)
				return (1);
		}
		else
			check_args(new[i]);
		i++;
	}
	clean_split(new);
	return (0);
}
