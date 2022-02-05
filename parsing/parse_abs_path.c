#include "parsing.h"

int	move_path(char **path)
{
	int		back;
	int		count;

	back = 0;
	count = 0;
	while (**path && ft_strchr("./", **path))
	{
		if (**path == '.')
			count++;
		if (**path == '/')
		{
			if (count == 2)
				back++;
			count = 0;
		}
		if (count > 2)
		{
			(*path)++;
			break ;
		}
		(*path)++;
	}
	*path -= count;
	return (back);
}

char	*move_pwd(int back, t_env *env)
{
	char	*pwd;
	int		len;

	pwd = env_get("PWD", env);
	if (!pwd)
		return (NULL);
	len = ft_strlen(pwd);
	while (back > 0)
	{
		if (len == 1)
			break ;
		if (pwd[len - 1] == '/')
			pwd[len - 1] = RCH;
		while (pwd[len - 1] != '/')
		{
			pwd[len - 1] = RCH;
			len--;
		}
		back--;
	}
	return (ft_remove_char(pwd, RCH));
}

char	*parse_abs_path(t_env *env, char *path)
{
	int		back;
	char	*pwd;
	char	*res;
	char	*tmp;

	while (*path && *path == ' ')
		path++;
	if (*path != '.')
		return (ft_strtrim(path, " \t"));
	back = move_path(&path);
	pwd = move_pwd(back, env);
	if (!pwd)
		return (NULL);
	if (back == 0)
	{
		tmp = pwd;
		pwd = ft_strjoin(tmp, "/");
	}
	res = ft_strjoin(pwd, path);
	return (res);
}
