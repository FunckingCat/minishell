#include "builtin.h"

int	cmd_pwd(char **args, t_env *env)
{
	char	*res;

	if (!env || !env->vars)
		return (put_error("pwd", "env is corrupted"));
	res = env_get("PWD", env);
	if (!res)
		return (1);
	ft_putstr_fd(res, 1);
	write (1, "\n", 1);
	return (0);
}
