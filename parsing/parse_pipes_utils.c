#include "parsing.h"

char	**free_res(char **res, int j)
{
	int	i;

	i = 0;
	while (i < j)
		free(res[i++]);
	free(res);
	return (NULL);
}

int	calc_chars_to_quotes(char *cmd)
{
	char	quote;
	int		i;

	i = 0;
	quote = *(cmd + i++);
	while (*(cmd + i) && *(cmd + i) != quote)
		i++;
	return (i);
}

char	**split_to_commands(char *cmd, int cmds, int i, int j)
{
	char	**res;

	res = malloc(sizeof(char *) * (cmds + 1));
	if (!res)
		return (NULL);
	while (j < cmds)
	{
		if (*(cmd + i) == '\"' || *(cmd + i) == '\'')
			i += calc_chars_to_quotes(cmd + i);
		if (*(cmd + i) == '|' || *(cmd + i) == '\0')
		{
			res[j] = malloc(sizeof(char) * (i + 1));
			if (!res[j])
				return (free_res(res, j));
			ft_strlcpy(res[j++], cmd, i + 1);
			cmd += i + 1;
			i = 1;
		}
		i++;
	}
	res[j] = NULL;
	return (res);
}