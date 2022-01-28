#include "parsing.h"

char	*skip_quotes(char *cmd)
{
	char	quote;

	quote = *cmd++;
	while(*cmd && *cmd != quote)
		cmd++;
	return (cmd);
}

char	*replace_pipes(char *cmd)
{
	int	len;

	len = ft_strlen(cmd);
	while (*cmd)
	{
		if (*cmd == '\'' || *cmd == '\"')
			cmd = skip_quotes(cmd);
		if (!*cmd)
			return(NULL);
		if (*cmd == '|')
			*cmd = RCH;
		cmd++;
	}
	return (cmd - len);
}

int	check_tail(char *cmd)
{
	while (*cmd == ' ')
		cmd--;
	if (*cmd == RCH)
		return (1);
	return (0);
}

int	check_pipes(char *cmd)
{
	int pipe_fl;

	pipe_fl = 0;
	while (*cmd == ' ')
			cmd++;
	if (*cmd == RCH)
		return (1);
	while (*cmd)
	{
		while (*cmd == ' ')
			cmd++;
		if (*cmd == RCH && pipe_fl)
			return (1);
		else if (*cmd == RCH)
			pipe_fl = 1;
		else
			pipe_fl = 0;
		if (*cmd)
			cmd++;
	}
	return (check_tail(cmd - 1));
}

int	parse_pipes(t_shell *shell, char *cmd)
{
	cmd = replace_pipes(cmd);
	if (!cmd)
		return (put_error(MINISHELL, Q_NCL));
	if (check_pipes(cmd))
		return (put_error(MINISHELL, SYNTAX_PIPE));
	shell->cmds_arr = ft_split(cmd, RCH);
	if (!shell->cmds_arr)
		return (1);
	while (*(shell->cmds_arr + shell->cmds))
		shell->cmds++;
	for (int i = 0; i < shell->cmds; i++)
		printf("%d > %s\n", i + 1, shell->cmds_arr[i]);
	return (0);
}
