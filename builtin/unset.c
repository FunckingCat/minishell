#include "builtin.h"

int	cmd_unset(char **args, t_env *env)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (!check_name(args[i]))
			env_delete(args[i], env);
		else
			put_ext_error(UNS, args[i], EXP_NOT_VALID);
		i++;
	}
	return (0);
}
