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
	return (res);
}

int	split_to_commands(t_shell *shell, char *cmd)
{
	int		i;
	int		j;
	char	quote;

	i = 0;
	j = 0;
	while (j < shell->cmds)
	{
		if (*(cmd + i) == '\"' || *(cmd + i) == '\'')
		{
			quote = *(cmd + i);
			i++;
			while (*(cmd + i) && *(cmd + i) != quote)
				i++;
		}
		if (*(cmd + i) == '|' || *(cmd + i) == '\0')
		{
			shell->cmds_arr[j] = malloc(sizeof(char) * (i + 1));
			if (!shell->cmds_arr[j])
				return (put_error(MINISHELL, "allocation error"));
			ft_strlcpy(shell->cmds_arr[j], cmd, i + 1);
			j++;
			cmd += i + 1;
			i = 0;
		}
		i++;
	}
	shell->cmds_arr[j] = NULL;
	return (0);
}

int	parse_pipes(t_shell *shell, char *cmd)
{
	shell->cmds = count_cmds(cmd);
	if (!shell->cmds)
		return (1);
	shell->cmds_arr = malloc(sizeof(char *) * (shell->cmds + 1));
	if (!shell->cmds_arr)
		return (put_error(MINISHELL, "allocation error"));
	printf("%d command\n", shell->cmds);
	split_to_commands(shell, cmd);
	printf("Finished\n");
	return (0);
}