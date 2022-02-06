#include "pipex.h"

t_cmd	*who_returned(t_shell *shell, pid_t pid)
{
	int	i;

	i = 0;
	while (i < shell->cmds)
	{
		if (shell->cmds_arr[i]->pid == pid)
			return (shell->cmds_arr[i]);
		i++;
	}
	return (NULL);
}

void	wait_children(t_shell *shell)
{
	int			i;
	int			ret;
	int			stat;
	t_cmd		*child;

	i = 0;
	stat = 0;
	while (i < shell->cmds)
	{
		ret = waitpid(0, &stat, 0);
		child = who_returned(shell, ret);
		env_set("?", ft_itoa(WEXITSTATUS(stat)), shell->env);
		env_set("_", child->cmd, shell->env);
		if (child)
		{
			if (child->out != 1)
				close(child->out);
			if (child->in != 0)
				close(child->in);
		}
		i++;
	}
}

int	set_in_out(t_shell *shell)
{
	int		i;
	int		pip[2];

	i = 1;
	while (i < shell->cmds)
	{
		if (pipe(pip) == -1)
			return (put_error(MINISHELL, PIPE_FAIL));
		shell->cmds_arr[i - 1]->out = pip[1];
		shell->cmds_arr[i]->in = pip[0];
		i++;
	}
	return (0);
}

int	pipex(t_shell *shell)
{
	int	i;

	i = 0;
	if (set_in_out(shell))
		return (1);
	while (i < shell->cmds)
	{
		if (parse_redirects(shell->cmds_arr[i]))
			return (1);
		if (parse_command(shell->cmds_arr[i], shell->env))
			return (1);
		i++;
	}
	if (shell->cmds == 1 && is_no_fork(shell->cmds_arr[0]->cmd))
		return (run_no_fork(shell->cmds_arr[0], shell->env));
	fork_proc(shell);
	wait_children(shell);
	return (0);
}
