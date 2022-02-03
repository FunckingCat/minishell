#include "parsing.h"

int	parse_command(t_cmd *cmd, t_env *env)
{
	if (!parse_redirects(cmd))
		return (1);
	cmd->args = ft_split(cmd->input, ' ');
	return (0);
}