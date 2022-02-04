#include "builtin.h"

void	clean_split(char **new_var)
{
	int	i;

	i = 0;
	while (new_var && new_var[i])
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
		return (put_error(EXP, EXP_NOT_VALID));
	if (!ft_isalpha(extra[0][0]))
		return (put_error(EXP, EXP_NOT_VALID));
	while (extra[0][i] != '\0')
	{
		if (!ft_isalnum(extra[0][i]) && extra[0][i] != '_')
		{
			clean_split(extra);
			return (put_error(EXP, EXP_NOT_VALID));
		}
		i++;
	}
	return (0);
}

int	set_element(t_env *envi, char *str)
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
		free(new);
		return (1);
	}
	free(new);
	clean_split(extra);
	return (0);
}

int	set_good_elem(t_env *envi, char *arg)
{
	if (arg[0] == '=')
		return (put_error_status(EXP, EXP_NOT_VALID, 0));
	else if (set_element(envi, arg))
		return (1);
	else
		return (0);
}

int	cmd_export(char **args, t_env *env)
{
	int i;

	i = 0;
	while (args && args[i])
	{
		if (ft_strchr(args[i], '='))
		{
			if (set_good_elem(env, args[i]) == 1)
				return (1);
		}
		else
			check_args(args[i]);
		i++;
	}
	return (0);
}
