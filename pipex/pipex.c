#include "pipex.h"

// t_command	*who_returned(t_shell *shell, pid_t pid)
// {
// 	int	i;

// 	i = 0;
// 	while (i < env->cmds)
// 	{
// 		if (env->pids[i] == pid)
// 			return (&env->commands[i]);
// 		i++;
// 	}
// 	return (NULL);
// }

// void	wait_children(t_shell *shell)
// {
// 	int			i;
// 	int			ret;
// 	t_command	*child;

// 	i = 0;
// 	while (i < env->cmds)
// 	{
// 		ret = wait(NULL);
// 		child = who_returned(env, ret);
// 		if (child)
// 		{
// 			if (child->out != 1)
// 				close(child->out);
// 			if (child->in != 0)
// 				close(child->in);
// 		}
// 		i++;
// 	}
// }

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
	printf(PURPLE "--------PIPEX-------\n" NONE);
	if (set_in_out(shell))
		return (1);
	for (int i = 0; i < shell->cmds; i++)
	{
		printf("cmd %d: %s in: %d out: %d\n", i, shell->cmds_arr[i]->full, shell->cmds_arr[i]->in, shell->cmds_arr[i]->out);
		if (parse_redirects(shell->cmds_arr[i]))
			return (1);
		printf("cmd %d: %s in: %d out: %d\n", i, shell->cmds_arr[i]->full, shell->cmds_arr[i]->in, shell->cmds_arr[i]->out);
	}
	//fork_proc(shell);
	//wait_children(env);
	return (0);
}
