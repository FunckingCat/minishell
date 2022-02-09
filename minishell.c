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
	shell->cmds_arr = ft_malloc(sizeof(t_cmd *) * shell->cmds);
	if (!shell->cmds_arr)
		return (put_error_null(MINISHELL, MALLOC_ERR));
	while (i < shell->cmds)
	{
		shell->cmds_arr[i] = new_cmd(ft_strtrim(parse[i], " \t"));
		i++;
	}
	return (NULL);
}

void	check_exit(t_shell *shell)
{
	int		i;
	char	**sp;

	i = 0;
	if (shell->cmds != 1)
		return ;
	sp = ft_split(shell->cmds_arr[0]->input, ' ');
	while (sp[i])
		i++;
	if (!ft_strcmp(sp[0], "exit"))
	{
		shell->exit = 1;
		if (i > 1)
			shell->exit_status = ft_atoi(sp[1]);
		if (i > 2)
			put_error("exit", "too many arguments");
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_shell	shell;
	char	*read;
	char	*str;

	if (init_shell(&shell, envp))
		return (1);
	while (!shell.exit)
	{
		read = readline(YELLOW PROMPT NONE);
		if (read == NULL )
		{
			write(1, "exit\n", 6);
			exit(0);
		}
		add_history(read);
		str = ft_strdup(read);
		free(read);
		str = parse_beautify(str);
		str = parse_global(str, shell.env);
		parse_commands(&shell, str);
		check_exit(&shell);
		pipex(&shell);
		shell_middle_clean(&shell);
	}
	shell_full_clean(&shell);
	return (shell.exit_status);
}
