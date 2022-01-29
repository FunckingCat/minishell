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

char	**parse_pipes(char *cmd)
{
	char	**res;
	cmd = replace_pipes(cmd);
	if (!cmd)
		return (put_error_null(MINISHELL, Q_NCL));
	if (check_pipes(cmd))
		return (put_error_null(MINISHELL, SYNTAX_PIPE));
	res = ft_split(cmd, RCH);
	if (!res)
		return (put_error_null(MINISHELL, MALLOC_ERR));
	return (res);
}
