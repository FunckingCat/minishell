#include "pipex.h"

char	*full_path(char *path, char *name)
{
	char	*tmp;
	char	*res;

	if (path[ft_strlen(path) - 1] != '/')
	{
		tmp = ft_strjoin(path, "/");
		res = ft_strjoin(tmp, name);
		free(tmp);
		return (res);
	}
	return (ft_strjoin(path, name));
}

void	run(t_shell *shell, t_cmd *cmd)
{
	char	**path;
	int		i;

	i = 0;
	if (is_builtin(cmd->cmd))
		run_builtin(cmd, shell->env);
	if (!ft_strcmp(ft_strtrim(cmd->cmd, " \t"), "exit"))
		exit(0);
	path = ft_split(env_get("PATH", shell->env), ':');
	execve(cmd->full_path, cmd->args, shell->env->vars);
	while (path[i] != NULL)
	{
		execve(full_path(path[i], cmd->cmd), cmd->args, shell->env->vars);
		i++;
	}
	put_error_exit(cmd->cmd, "command not found", 127);
}

void	close_descriptors(t_shell *shell)
{
	int	i;

	i = 0;
	while (i < shell->cmds)
	{
		if (shell->cmds_arr[i]->in != 0)
			close(shell->cmds_arr[i]->in);
		if (shell->cmds_arr[i]->out != 1)
			close(shell->cmds_arr[i]->out);
		i++;
	}
}

void	exec(t_cmd *cmd, t_shell *shell)
{
	if (dup2(cmd->in, 0) == -1 || dup2(cmd->out, 1) == -1)
		put_error_exit("dup2", "dup failed", 1);
	close_descriptors(shell);
	run(shell, cmd);
}

int	fork_proc(t_shell *shell)
{
	int	i;

	i = 0;
	while (i < shell->cmds)
	{
		shell->cmds_arr[i]->pid = fork();
		if (shell->cmds_arr[i]->pid == -1)
			put_error("fork", "fork failed");
		else if (shell->cmds_arr[i]->pid == 0)
			exec(shell->cmds_arr[i], shell);
		i++;
	}
	return (0);
}
