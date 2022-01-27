#include "builtin.h"

void	clean_split(char **new_var)
{
	int	i;

	i = 0;
	while (new_var[i])
	{
		free(new_var[i]);
		i++;
	}
	free(new_var);
}

int	export(t_env *envi, char *str)
{
	char	**new_var;
	int		i;

	i = 0;
	if (!str)
		return (1);
	new_var = ft_split(str, '=');
	while (new_var[i])
		i++;
	if (i == 2)
		env_set(new_var[0], new_var[1], envi);
	else
	{
		put_error(EXP, EXP_PAR);
		clean_split(new_var);
		return (1);
	}
	clean_split(new_var);
	return (0);
}
