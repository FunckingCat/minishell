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
		if (ft_strlen(read) > 0)
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
