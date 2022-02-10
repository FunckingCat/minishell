#include "shell.h"

int	init_shell(t_shell *shell, char **envp)
{
	char	*buf;

	shell->exit = 0;
	shell->exit_status = 0;
	shell->cmds = 0;
	shell->cmds_arr = NULL;
	shell->skip = 0;
	shell->read = NULL;
	shell->pid_c = 0;
	shell->env = env_init(envp);
	if (!shell->env)
		return (1);
	buf = ft_itoa(ft_atoi(env_get("SHLVL", shell->env)) + 1);
	env_set("SHLVL", buf, shell->env);
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
