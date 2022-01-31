#include "env.h"

char	*env_get(char *name, t_env *envi)
{
	char	*deffin;
	int		i;

	i = 0;
	if (!name || !envi || !envi->vars)
	{
		put_error(ENV, ENV_NO_PAR);
		return (NULL);
	}
	while (envi->vars[i])
	{
		if (ft_strncmp(envi->vars[i], name, ft_strlen(name)) == 0)
		{
			deffin = ft_strdup(&envi->vars[i][ft_strlen(name) + 1]);
			if (deffin == NULL)
				return (NULL);
			else
				return (deffin);
		}
		i++;
	}
	return (NULL);
}
