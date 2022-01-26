# include "env.h"

char	*env_get(char *name, t_env *envi)
{
	int i ;

	i = 0;
	if (!envi->env || !name)
		printf("error"); // обработать ошибку
	while (envi->env[i])
	{
		printf("string \n");
		if (ft_strncmp(envi->env[i], name, ft_strlen(name)))
			printf ("%s \n", envi->env[i]);
		i++;
	}
	return (NULL);
}
int main(int argc, char **argv , char **envp)
{
	t_env *envi;

	envi = init_env(envp);
	env_get("PWD", envi);
	return (0);
}