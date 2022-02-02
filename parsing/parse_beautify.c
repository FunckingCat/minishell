#include "parsing.h"


char	*parse_beautify(char *str)
{
	char	*tmp;
	char	q;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp = malloc(sizeof(char) * (ft_strlen(str) + 1));
	while(str[i])
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
	free(str);
	str = ft_strdup(tmp);
	free(tmp);
	return(str);
}