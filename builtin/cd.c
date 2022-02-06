#include "builtin.h"

int	check_amount(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	if (i > 1)
		return (1);
	return (0);
}

int	cmd_cd(char **args, t_env *env)
{
	char	*buff;
	int		status;

	status = 0;
	if (check_amount(args) == 1)
		return (put_error(CD, CD_MN_ARGS));
	if (chdir(args[0]) == -1)
		return (put_error(CD, CD_NO_FILE));
	buff = env_get("PWD", env);
	if (!buff)
		return (put_error(CD, MALLOC_ERR));
	if (env_set("OLDPWD", buff, env))
		status = 1;
	buff = getcwd(NULL, 1044480);
	if (!buff)
		return (put_error(CD, MALLOC_ERR));
	if (env_set("PWD", buff, env))
		status = 1;
	return (status);
}
