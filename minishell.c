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

int	check_exit_ctrl_d(char *read)
{
	if (!read)
	{
		write(1, "\nexit\n", 6);
		return (1);
	}
	return (0);
}

int	check_int_skip(char **read)
{
	if (g_shell.skip == 1)
	{
		g_shell.skip = 0;
		free(*read);
	}
}

t_shell	g_shell;

int	main(int argc, char **argv, char **envp)
{
	char	*str;

	if (init_shell(&g_shell, envp))
		return (1);
	signal(SIGQUIT, SIG_IGN);
	while (!g_shell.exit)
	{
		signal(SIGINT, sig_int_empty);
		g_shell.read = readline(YELLOW PROMPT NONE);
		if (check_exit_ctrl_d(g_shell.read))
			break ;
		if (check_int_skip(&g_shell.read))
			continue ;
		add_history(g_shell.read);
		str = ft_strdup(g_shell.read);
		free(g_shell.read);
		str = parse_beautify(str);
		str = parse_global(str, g_shell.env);
		parse_commands(&g_shell, str);
		check_exit(&g_shell);
		pipex(&g_shell);
		shell_middle_clean(&g_shell);
	}
	shell_full_clean(&g_shell);
	return (g_shell.exit_status);
}
