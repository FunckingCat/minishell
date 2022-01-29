#include "minishell.h"

int	init_shell(t_shell *shell, char **envp)
{
	shell->cmds = 0;
	shell->cmds_arr = NULL;
	shell->env = env_init(envp);
	if (!shell->env)
		return (1);
	return (0);
}

int	free_last_commands_data(t_shell *shell)
{
	int	i;

	printf(PURPLE "Commands clean\n" NONE);
	if (shell->cmds_arr)
	{
		i = 0;
		while (i < shell->cmds)
		{
			// if (shell->cmds_arr[i])
			// 	free(shell->cmds_arr[i]);
			i++;
		}
		free(shell->cmds_arr);
	}
	shell->cmds = 0;
	return (0);
}

void	command_routine(t_shell *shell, char *cmd)
{
	char	**parse;

	parse = parse_pipes(cmd);
	if (!parse)
		return ;
}

int	main(int argc, char **argv, char **envp)
{

	t_shell	shell;

	if (init_shell(&shell, envp))
		return (1);
	while (1)
	{
		char * str = readline(YELLOW PROMPT NONE);
		add_history(str);
		command_routine(&shell, str);
		free(str);
	}
	env_free(shell.env);
	return (0);
}