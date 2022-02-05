#include "parsing.h"

void	cp(char *str, char *tmp)
{
	char	q;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			q = str[i];
			tmp[j++] = str[i++];
			while (str[i] && str[i] != q)
				tmp[j++] = str[i++];
		}
		if (!ft_strchr(" \t", str[i]))
			tmp[j++] = str[i];
		else if (i != 0 && !ft_strchr(" \t", str[i - 1]))
			tmp[j++] = str[i];
		i++;
	}
	tmp[j] = 0;
}

char	*parse_beautify(char *str)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_malloc(sizeof(char) * (ft_strlen(str) + 1));
	cp(str, tmp);
	while (tmp[i])
	{
		if (tmp[i] == '\t')
			tmp[i] = ' ';
		i++;
	}
	return (ft_strdup(tmp));
}
