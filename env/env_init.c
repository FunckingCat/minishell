#include "env.h"

int	get_memory_env(char **envp, t_env *envi)
{
	int	i;
	int	j;

	i = 0;
	while (i < envi->length)
	{
		envi->vars[i] = ft_strdup(envp[i]);
		i++;
	}
	envi->vars[i] = NULL;
	return (0);
}

t_env	*malloc_return_pointer(t_env *envi)
{
	put_error(ENV, ENV_MALLOC);
	if (envi)
		free(envi);
	return (NULL);
}

t_env	*env_init(char **envp)
{
	t_env	*envi;
	int		count;

	count = 0;
	while (envp[count])
		count++;
	envi = malloc(sizeof(t_env));
	if (!envi)
		return (malloc_return_pointer(envi));
	envi->length = count;
	envi->vars = malloc(sizeof(char *) * (envi->length + 1));
	if (!envi->vars)
		return (malloc_return_pointer(envi));
	if (get_memory_env(envp, envi))
		return (malloc_return_pointer(envi));
	return (envi);
}
