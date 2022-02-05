#include "builtin.h"

int check_name(char *arg)
{
	int i;

	i = 0;
	if (!ft_isalpha(arg[0]))
		return (1);
	while (arg[i] != '\0')
	{
		if (!ft_isalnum(arg[i]) && arg[i] != '_')
			return (1);
		i++;
	}
	return (0);
}

int	set_element(t_env *env, char *arg)
{
	char	*name;
	char	*value;
	char	**spl;
	int		status;

	if (arg[0] == '=' || !ft_strchr(arg, '='))
		return (put_error(EXP, EXP_NOT_VALID));
	spl = ft_split(arg, '=');
	name = spl[0];
	value = ft_strchr(arg, '=') + 1;
	if (check_name(name) || check_name(value))
		return (put_error(EXP, EXP_NOT_VALID));
	status = env_set(name, value, env);
	return (status);
}

int	cmd_export(char **args, t_env *env)
{
	int i;

	i = 0;
	while (args && args[i])
	{
		if (set_element(env, args[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}
