#include "builtin.h"

int cd(char *arg, t_env *envi)
{
	char *new_pwd;
	char *old_pwd;
	char buff[104480];

	old_pwd = env_get("PWD", envi);
	if (chdir(arg) == -1 || !old_pwd)
		return (1);
	getcwd(buff, 1044480);
	new_pwd = ft_strdup(buff);
	env_set("PWD", new_pwd, envi);
	env_set("OLDPWD", old_pwd, envi);
	if (env_set("PWD", new_pwd, envi)
		|| env_set("OLDPWD", old_pwd, envi))
	{
		free(old_pwd);
		free(new_pwd);
		return (1);
	}
	free(old_pwd);
	free(new_pwd);
	return (0);
}