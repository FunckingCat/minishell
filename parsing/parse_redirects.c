#include "parsing.h"

int	calc_red_len(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i] && ft_strchr("<>", cmd[i]))
		i++;
	while (cmd[i] == ' ')
		i++;
	while (cmd[i] && !ft_strchr("<> ", cmd[i]))
		i++;
	return (i);
}

int	parse_redirects(t_cmd *cmd)
{
	int			i;
	int			len;
	char		*tmp;

	i = 0;
	while ((cmd->full)[i])
	{
		if (ft_strchr("<>", cmd->full[i]))
		{
			len = calc_red_len(cmd->full + i);
			tmp = malloc(len + 1);
			ft_strlcpy(tmp, cmd->full + i, len + 1);
			add_redirect(cmd, tmp);
			ft_memset(cmd->full + i, RCH, len);
			free(tmp);
			i += len;
		}
		else
			i++;
	}
	cmd->full = ft_remove_char(cmd->full, RCH);
	return (0);
}