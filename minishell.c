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
	if (!ft_strcmp(sp[0], EXIT))
	{
		shell->exit = 1;
		if (i > 1)
			shell->exit_status = ft_atoi(sp[1]);
		if (i > 1 && !ft_isstrdigit(sp[1]))
		{
			put_ext_error(EXIT, sp[1], EXIT_ERR_ARGS);
			shell->exit_status = 255;
		}
		else if (i > 2)
		{
			shell->exit = 0;
			put_error(EXIT, EXIT_ERR_NUM);
		}
	}
}

int  check_exit_ctrl_d(char *read)
{
	if (!read)
	{
		write(1, "\nexit\n", 6);
		return (1);
	}
	return (0);
}

int  check_int_skip(t_shell *shell, char *read)
{
	if (shell->skip == 1)
	{
		shell->skip = 0;
		free(read);
	}
}

int  main(int argc, char **argv, char **envp)
{
	t_shell	shell;
	char	*read;
	char	*str;

	g_heap.ptr = (void *)&shell;
	if (init_shell(&shell, envp))
		return (1);
	signal(SIGQUIT, SIG_IGN);
	while (!shell.exit)
	{
		signal(SIGINT, sig_int_empty);
		read = readline(YELLOW PROMPT NONE);
		if (check_exit_ctrl_d(read))
			break ;
		if (check_int_skip(&shell, read))
			continue ;
		if (ft_strlen(read) > 0)
			add_history(read);
		str = ft_strdup(read);
		free(read);
		str = parse_beautify(str);
		str = parse_global(str, shell.env);
		parse_commands(&shell, str);
		check_exit(&shell);
		pipex(&shell);
		shell.cmds = 0;
	}
	ft_free();
	return (shell.exit_status);
}