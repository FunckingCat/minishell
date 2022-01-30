#include "shell.h"

int	init_shell(t_shell *shell, char **envp)
{
	shell->cmds = 0;
	shell->cmds_arr = NULL;
	shell->env = env_init(envp);
	if (!shell->env)
		return (1);
	return (0);
}