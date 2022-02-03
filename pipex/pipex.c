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
	t_cmd		*child;

	i = 0;
	while (i < shell->cmds)
	{
		ret = wait(NULL);
		child = who_returned(shell, ret);
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
			return (put_error(MINISHELL, "pipe create failed"));
		shell->cmds_arr[i - 1]->out = pip[1];
		shell->cmds_arr[i]->in = pip[0];
		i++;
	}
	return (0);
}

int	pipex(t_shell *shell)
{
	if (set_in_out(shell))
		return (1);
	fork_proc(shell);
	wait_children(shell);
	return (0);
}
