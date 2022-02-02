#include "parsing.h"

char	*get_name(char *cmd)
{
	char	*tmp;

	if (*cmd++ != '$')
		return (NULL);
	cmd = ft_strdup(cmd);
	tmp = cmd;
	if (ft_isalnum(*tmp) || *tmp == '_')
	{
		while (ft_isalnum(*tmp) || *tmp == '_')
			tmp++;
		while(*tmp)
			*tmp++ = RCH;
		cmd = ft_remove_char(cmd, RCH);
		return (cmd);
	}
	free(cmd);
	return (NULL);
}

int	calc_length(char *cmd, t_env *env)
{
	int		i;
	char	*name;

	i = 0;
	while (*cmd)
	{
		if (*cmd == '\'')
		{
			while (*cmd && *cmd != '\'')
			{
				cmd++;
				i++;
			}
		}
		name = get_name(cmd);
		if (name)
		{
			i += ft_strlen(env_get(name, env)) - 1;
			cmd += ft_strlen(name);
			free(name);
		}
		i++;
		cmd++;
	}
	return (i + 1);
}

char	*parse_global(char *cmd, t_env *env)
{
	char	*res;
	char	*name;
	char	*val;
	int		i;
	int		j;
	int		k;

	res = malloc(sizeof(char) * calc_length(cmd, env));
	i = 0;
	j = 0;
	while (cmd[i])
	{
		if (cmd[i] == '\'')
		{
			res[j++] = cmd[i++];
			while (cmd[i] && cmd [i] != '\'')
				res[j++] = cmd[i++];
		}
		name = get_name(cmd + i);
		if (name)
		{
			cmd += ft_strlen(name) + 1;
			val = env_get(name, env);
			k = 0;
			while (val[k])
				res[j++] = val[k++];
			free(name);
			free(val);
		}
		else
			res[j++] = cmd[i++];
	}
	res[j] = '\0';
	return (res);
}
