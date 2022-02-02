#include "parsing.h"

char	*get_name(char *cmd)
{
	char	*tmp;

	if (*cmd != '$')
		return (NULL);
	cmd = ft_strdup(cmd);
	tmp = cmd;
	while (*tmp != ' ')
		tmp++;
	while (*tmp)
		*tmp++ = RCH;
	cmd = ft_remove_char(cmd, RCH);
	return (cmd);
}

int	parse_global(char *cmd, t_env *env)
{
	char	*res;
	char	*gval;

	res = malloc;
}