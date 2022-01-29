#include "builtin.h"

void check_args(char *extra)
{
	int i;

	i = 0;
	while (extra[i] != '\0')
	{
		if ((extra[0] > 47 && extra[0] < 58)
			|| (!(extra[i] > 47 && extra[i] < 58)
			&& !(extra[i] > 64 && extra[i] < 91)
			&& !(extra[i] > 96 && extra[i] < 123)
			&& extra[i] != '_'))
		{
			put_error(EXP, EXP_NOT_VALID);
			return ;
		}
		i++;
	}
}

int	unset(t_env *envi, char *args)
{
	char **names;
	int i;

	i = 0;
	names = ft_split(args, ' ');
	if (!names)
		return (1);
	while (names[i])
	{
		check_args(names[i]);
		if (env_delete(names[i], envi) == 1)
		{
			clean_split(names);
			return (1);
		}
		i++;
	}
	clean_split(names);
	return (0);
}
