#include "minishell.h"

int	init_shell(t_shell *shell)
{
	shell->cmds = 0;
	shell->cmds_arr = NULL;
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
			//if (shell->cmds_arr[i])
			//	free(shell->cmds_arr[i]);
			i++;
		}
		free(shell->cmds_arr);
	}
	shell->cmds = 0;
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_shell	shell;

	init_shell(&shell);
	while (1)
	{
		char * str = readline(YELLOW PROMPT NONE);
		add_history(str);
		parse_pipes(&shell, str);
		free(str);
		free_last_commands_data(&shell);
	}
	return (0);
}