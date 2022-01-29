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

int	free_commands_data(t_shell *shell)
{
	int	i;

	printf(PURPLE "Commands clean\n" NONE);
	if (shell->cmds_arr)
	{
		i = 0;
		while (i < shell->cmds)
		{
			if (shell->cmds_arr[i].full)
				free(shell->cmds_arr[i].full);
			i++;
		}
		free(shell->cmds_arr);
	}
	shell->cmds = 0;
	return (0);
}



void	*parse_commands(t_shell *shell, char *cmd)
{
	char	**parse;
	int		i;

	i = 0;
	parse = parse_pipes(cmd);
	if (!parse)
		return (NULL);
	while (*(parse + shell->cmds))
		shell->cmds++;
	shell->cmds_arr = malloc(sizeof(t_cmd) * shell->cmds);
	if (!shell->cmds_arr)
		return(put_error_null(MINISHELL, MALLOC_ERR));
	while (i < shell->cmds)
	{
		shell->cmds_arr[i].full = ft_strtrim(parse[i], " \t");
		printf(PURPLE "cmd %d: %s\n" NONE, i, shell->cmds_arr[i].full);
		shell->cmds_arr[i].in = 0;
		shell->cmds_arr[i].out = 1;
		free(parse[i++]);
	}
	free(parse);
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
		parse_commands(&shell, str);
		free(str);
		free_commands_data(&shell);
	}
	env_free(shell.env);
	return (0);
}