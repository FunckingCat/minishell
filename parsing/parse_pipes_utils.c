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

char	*def_command(char **res, int j, char *cmd, int i)
{
	char	*res;
}

char	**split_to_commands(char *cmd, int cmds)
{
	char	**res;
	int		i;
	int		j;
	char	quote;

	i = 0;
	j = 0;
	res = malloc(sizeof(char *) * (cmds + 1));
	if (!res)
		return (NULL);
	while (j < cmds)
	{
		if (*(cmd + i) == '\"' || *(cmd + i) == '\'')
		{
			quote = *(cmd + i++);
			while (*(cmd + i) && *(cmd + i) != quote)
				i++;
		}
		if (*(cmd + i) == '|' || *(cmd + i) == '\0')
		{
			res[j] = malloc(sizeof(char) * (i + 1));
			if (!res[j])
				return (free_res(res, j));
			ft_strlcpy(res[j], cmd, i + 1);
			j++;
			cmd += i + 1;
			i = 0;
		}
		i++;
	}
	res[j] = NULL;
	return (res);
}