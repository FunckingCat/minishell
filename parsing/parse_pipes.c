#include "parsing.h"

int	check_double_pipe(char *cmd)
{
	int	i;

	i = 1;
	while (cmd[i] == ' ')
		i++;
	if (cmd[i] == '|')
		return (1);
	return (0);
}

int	check_reverse_pipe(char *cmd)
{
	int	i;

	i = 1;
	while (*(cmd - i) == ' ')
		i++;
	if (*(cmd - i) == '|')
		return (1);
	return (0);
}

int	count_cmds(char *str)
{
	int		res;
	char	qoute;

	res = 1;
	if (*str == '|' || (*str == ' ' && check_double_pipe(str)))
		return (put_error(MINISHELL, SYNTAX_PIPE) - 1);
	while (*str)
	{
		if (*str == '|' && res++ > 0)
			if (check_double_pipe(str))
				return (put_error(MINISHELL, SYNTAX_PIPE) - 1);
		if (*str == '\"' || *str == '\'')
		{
			qoute = *str;
			str++;
			while (*str && *str != qoute)
				str++;
		}
		if (!(*str))
			return (put_error(MINISHELL, Q_NCL) - 1);
		str++;
	}
	if (check_reverse_pipe(str))
		return (put_error(MINISHELL, SYNTAX_PIPE) - 1);
	return (res);
}

int	parse_pipes(t_shell *shell, char *cmd)
{
	shell->cmds = count_cmds(cmd);
	if (!shell->cmds)
		return (1);
	printf("%d command\n", shell->cmds);
	shell->cmds_arr = split_to_commands(cmd, shell->cmds, 0, 0);
	if (!shell->cmds_arr)
		return (put_error(MINISHELL, "allocation error"));
	for (int i = 0; i < shell->cmds; i++)
		printf("--> %s\n", shell->cmds_arr[i]);
	return (0);
}
