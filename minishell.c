#include "minishell.h"

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
	shell->cmds_arr = malloc(sizeof(t_cmd *) * shell->cmds);
	if (!shell->cmds_arr)
		return(put_error_null(MINISHELL, MALLOC_ERR));
	while (i < shell->cmds)
	{
		shell->cmds_arr[i] = new_cmd(ft_strtrim(parse[i], " \t"));
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
		pipex(&shell);
		free(str);
		shell_middle_clean(&shell);
	}
	shell_full_clean(&shell);
	return (0);
}