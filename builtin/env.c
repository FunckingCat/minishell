#include "builtin.h"

int	cmd_env(char **args, t_env *env)
{
	int	i;

	i = 0;
	if (!env || !env->vars)
		return (put_error(ENV, "env is corrupted"));
	if (check_amount(args) > 0)
		return (put_error(ENV, CD_MN_ARGS));
	while (i < env->length)
	{
		ft_putstr_fd(env->vars[i], 1);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
