#include "env.h"

int	get_memory_env(char **envp, t_env *envi, int count)
{
	int i;
	int j;

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
	return (0);
}


t_env *init_env(char **envp)
{
	int count;
	t_env envi;

	count = 0;
	while (envp[count])
		count++;
	envi.env = malloc(sizeof(char*) * count);
	if (!envi.env || get_memory_env(envp, &envi, count))
	{
		put_error(ENV, ENV_MALLOC);
		return (NULL);
	}
	return (&envi);
}

// int main(int argc, char *argv[], char **envp)
// {
// 	int i;
// 	t_env *envi;

// 	i = 0;
// 	// while (i < 29)
// 	// {
// 	// 	printf("--------%s\n", envp[i]);
// 	// 	i++;
// 	// }
// 	envi = init_env(envp);
// 	while (i < 29)
// 	{
// 		printf("%s\n", envi->env[i]);
// 		i++;
// 	}
// 	return (0);
// }