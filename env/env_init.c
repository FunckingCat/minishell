#include "env.h"

int	get_memory_env(char **envp, t_env *envi, int count)
{
	int	i;
	int	j;

	i = 0;
	while (i < count)
	{
		envi->env[i] = malloc(sizeof(char) * (ft_strlen(envp[i]) + 1));
		if (!envi->env[i])
			return (1);
		j = 0;
		while (j < ft_strlen(envp[i]))
		{
			envi->env[i][j] = envp[i][j];
			j++;
		}
		envi->env[i][j] = '\0';
		i++;
	}
	envi->env[i] = NULL;
	return (0);
}

void	init_struct(t_env *envi)
{
	envi->env = NULL;
}

int	init_env(t_env *envi, char **envp)
{
	int	count;

	count = 0;
	while (envp[count])
		count++;
	envi->env = malloc(sizeof(char *) * (count + 1));
	get_memory_env(envp, envi, count);
	if (envi->env == NULL)
	{
		put_error(ENV, ENV_MALLOC);
		return (1);
	}
	return (0);
}

// int	main(int argc, char *argv[], char **envp)
// {
// 	int i;
// 	t_env envi;

// 	i = 0;
// 	// while (i < 29)
// 	// {
// 	// 	printf("--------%s\n", envp[i]);
// 	// 	i++;
// 	// }
// 	init_env(&envi, envp);
// 	// while (i < 29)
// 	// {
// 	// 	printf("%s\n", envi->env[i]);
// 	// 	i++;
// 	// }
// 	while (i < 29)
// 	{
// 		ft_putstr_fd (envi.env[i], 1);
// 		write(1, "\n", 1);
// 		i++;
// 	}
// 	return (0);
// }