#include "builtin.h"

int	check_amount(char *str)
{
	char **args;
	int i;

	i = 0;
	if (str)
		args = ft_split(str, ' ');
	else
		return (0);
	if (!args)
		return (1);
	while (args[i])
		i++;
	if (i > 1)
	{
		clean_split(args);
		return (put_error(CD, CD_MN_ARGS));
	}
	clean_split(args);
	return (0);	
}

int extra_clean(char *old_pwd, char *new_pwd, char *buff , int st)
{
	if (old_pwd)
		free(old_pwd);
	if (new_pwd)
		free(new_pwd);
	if (buff)
		free(buff);
	return (st);
}

int cd(char *arg, t_env *envi)
{
	char *new_pwd;
	char *old_pwd;
	char *buff;

	if (check_amount(arg) == 1)
		return (1);
	old_pwd = env_get("PWD", envi);
	if (chdir(arg) == -1 || !old_pwd)
	{
		if (old_pwd)
			free(old_pwd);
		return(put_error(CD, CD_NO_FILE));
	}
	buff = getcwd(NULL, 1044480);
	if (!buff)
	{
		free(old_pwd);
		return (1);
	}	
	new_pwd = ft_strdup(buff);
	if (!new_pwd || env_set("PWD", new_pwd, envi)
		|| env_set("OLDPWD", old_pwd, envi))
		return (extra_clean(old_pwd, new_pwd, buff , 1));
	return (extra_clean(old_pwd, new_pwd, buff , 0));
}