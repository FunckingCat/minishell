#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_env *envi;


	envi = env_init(envp);
	cd ("../../", envi);
	ft_putstr_fd(env_get("PWD", envi), 1);
	write(1, "\n", 1);
	ft_putstr_fd(env_get("OLDPWD", envi), 1);
	// printf("%s\n", env_get("OLDPWD", envi));
	// printf("%s\n", env_get("PWD", envi));
	return (0);
}