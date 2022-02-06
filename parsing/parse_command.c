#include "parsing.h"

char	*remove_quotes(char *cmd)
{
	char	*tmp;
	char	quote;

	tmp = cmd;
	while (*tmp)
	{
		if (*tmp == '\'' || *tmp == '\"')
		{
			quote = *tmp;
			*tmp = RCH;
			while (*tmp && *tmp != quote)
				tmp++;
			if (*tmp == '\'' || *tmp == '\"')
				*tmp++ = RCH;
		}
		tmp++;
	}
	return (ft_remove_char(cmd, RCH));
}

int	parse_command(t_cmd *cmd, t_env *env)
{
	int		i;
	char	*tmp;

	tmp = cmd->input;
	while (*tmp)
	{
		if (*tmp == ' ')
			*tmp = RCH;
		if (*tmp == '\'' || *tmp == '\"')
			tmp = skip_quotes(tmp);
		tmp++;
	}
	cmd->args = ft_split(cmd->input, RCH);
	i = 0;
	while (cmd->args[i])
	{
		cmd->args[i] = remove_quotes(cmd->args[i]);
		i++;
	}
	cmd->cmd = cmd->args[0];
	cmd->full_path = parse_abs_path(env, cmd->cmd);
	return (0);
}
