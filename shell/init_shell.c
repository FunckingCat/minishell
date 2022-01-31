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
	int	i;

	if (shell->cmds_arr)
	{
		i = 0;
		while (i < shell->cmds)
		{
			if (shell->cmds_arr[i])
				free_cmd(shell->cmds_arr[i]);
			i++;
		}
		free(shell->cmds_arr);
	}
	shell->cmds = 0;
	return (0);
}

int	shell_full_clean(t_shell *shell)
{
	env_free(shell->env);
	return (0);
}