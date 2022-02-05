#include "shell.h"

int	init_shell(t_shell *shell, char **envp)
{
	shell->exit = 0;
	shell->cmds = 0;
	shell->cmds_arr = NULL;
	shell->env = env_init(envp);
	if (!shell->env)
		return (1);
	return (0);
}

int	shell_middle_clean(t_shell *shell)
{
	shell->cmds = 0;
	return (0);
}

int	shell_full_clean(t_shell *shell)
{
	ft_free();
	return (0);
}