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

void	check_exit(t_shell *shell)
{
	int		i;
	char	**sp;

	i = 0;
	if (shell->cmds != 1)
		return ;
	sp = ft_split(shell->cmds_arr[0]->full, ' ');
	while (sp[i])
		i++;
	if (i != 1)
		return ;
	if (!ft_strcmp(sp[0], "exit"))
		shell->exit = 1;
	i = 0;
	while (sp[i])
		free(sp[i++]);
	free(sp);
}

int	main(int argc, char **argv, char **envp)
{
	t_shell	shell;
	char	*str;

	if (init_shell(&shell, envp))
		return (1);
	while (!shell.exit)
	{
		// str = readline(YELLOW PROMPT NONE);
		// add_history(str);
		str = get_next_line(0);
		parse_commands(&shell, str);
		free(str);
		check_exit(&shell);
		pipex(&shell);
		shell_middle_clean(&shell);
	}
	shell_full_clean(&shell);
	return (0);
}