# include "env.h"

int	check_line(char *name, char *str, char **deffin)
{
	int	j;
	int	i;
	int	size_str;

	size_str = ft_strlen(str) - ft_strlen(name);
	*deffin = malloc(sizeof(char) * (size_str + 1));
	if (*deffin == NULL)
	{
		put_error(ENV, ENV_MALLOC);
		return (1);
	}
	j = ft_strlen(name) + 1;
	i = 0;
	while (str[j] != '\0')
	{
		(*deffin)[i] = str[j];
		j++;
		i++;
	}
	(*deffin)[i] = '\0';
	return (0);
}

char	*env_get(char *name, t_env *envi)
{
	char	*deffin;
	int		i;

	if (name == NULL || envi->env == NULL)
	{
		put_error(ENV, ENV_NO_PAR);
		return (NULL);
	}
	while (envi->env[i])
	{
		if (ft_strncmp(envi->env[i], name, ft_strlen(name)) == 0)
		{
			if (check_line(name, envi->env[i], &deffin) == 1)
				return (NULL);
			else
				return (deffin);
		}
		i++;
	}
	return (NULL);
}

// int main(int argc, char **argv , char **envp)
// {
// 	t_env envi;

// 	init_env(&envi, envp);
// 	int i =0;
// 	ft_putstr_fd(env_get("LANG", &envi), 1);
// 	return (0);
// }