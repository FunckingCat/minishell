#include "parsing.h"

char	*get_name(char *cmd)
{
	char	*tmp;

	if (*cmd++ != '$')
		return (NULL);
	if (*cmd == '?' || ft_isdigit(*cmd))
		return (ft_substr(cmd, 0, 1));
	cmd = ft_strdup(cmd);
	tmp = cmd;
	if (ft_isalnum(*tmp) || *tmp == '_')
	{
		while (ft_isalnum(*tmp) || *tmp == '_')
			tmp++;
		while (*tmp)
			*tmp++ = RCH;
		cmd = ft_remove_char(cmd, RCH);
		return (cmd);
	}
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
		}
		i++;
		cmd++;
	}
	return (i + 1);
}

char	*get_val(char	*cmd, int	*i, t_env	*env)
{
	char	*name;
	char	*val;

	name = get_name(cmd + *i);
	if (name)
	{
		*i += ft_strlen(name) + 1;
		val = env_get(name, env);
		return (val);
	}
	return (NULL);
}

void	skip(char *cmd, char *res, int *i, int *j)
{
	if (cmd[*i] == '\'')
	{
		res[(*j)++] = cmd[(*i)++];
		while (cmd[*i] && cmd [*i] != '\'')
			res[(*j)++] = cmd[(*i)++];
	}
}

char	*parse_global(char *cmd, t_env *env)
{
	char	*res;
	char	*val;
	int		i;
	int		j;

	res = ft_malloc(sizeof(char) * calc_length(cmd, env));
	i = 0;
	j = 0;
	while (cmd[i])
	{
		skip(cmd, res, &i, &j);
		val = get_val(cmd, &i, env);
		if (val)
		{
			ft_strlcpy(res + j, val, ft_strlen(val) + 1);
			j += ft_strlen(val);
		}
		else
			res[j++] = cmd[i++];
	}
	res[j] = '\0';
	return (res);
}
