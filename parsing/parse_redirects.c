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
	t_redirect	*new;

	i = 0;
	cmd->left = NULL;
	cmd->right = NULL;
	while ((cmd->full)[i])
	{
		if (ft_strchr("<>", cmd->full[i]))
		{
			len = calc_red_len(cmd->full + i);
			tmp = malloc(len + 1);
			ft_strlcpy(tmp, cmd->full + i, len + 1);
			printf(PURPLE "RD: %s\n" NONE, tmp);
			ft_memset(cmd->full + i, RCH, len);
			new = new_redirect(tmp);
			if (!new)
				return (1);
			if (new->type == RD_IN || new->type == RD_DIN)
			{
				free_redirect(cmd->left);
				cmd->left = new;
			}
			else
			{
				free_redirect(cmd->right);
				cmd->right = new;
			}
			free(tmp);
			i += len;
		}
		else
			i++;
	}
	cmd->full = ft_remove_char(cmd->full, RCH);
	cmd->in = cmd->left->fd;
	cmd->out = cmd->right->fd;
	return (0);
}