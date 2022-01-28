#include "builtin.h"

int	pwd(t_env *envi)
{
	char	*oldstr;
	char	*newpwd;

	if (!envi || !envi->vars)
	{
		put_error(EXP, EXP_PAR);
		return (1);
	}
	oldstr = env_get("PWD", envi);
	newpwd = getcwd(NULL, 1044480);
	if (env_set("PWD", newpwd, envi)
		|| env_set("OLDPWD", oldstr, envi))
	{
		free(oldstr);
		free(newpwd);
		return (1);
	}
	free(oldstr);
	free(newpwd);
	return (0);
}