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
	char	**ac;
	char	**path;
	int		i;

	i = 0;
	ac = ft_split(cmd->full, ' ');
	if (!ft_strcmp(ft_strtrim(cmd->full, " \t"), "exit"))
		exit(0);
	path = ft_split(env_get("PATH", shell->env), ':');
	cmd->cmd = parse_abs_path(shell->env, ac[0]);
	execve(cmd->cmd, ac, shell->env->vars);
	while (path[i] != NULL)
	{
		execve(full_path(path[i], cmd->cmd), ac, shell->env->vars);
		i++;
	}
	put_error_exit(ac[0], "command not found");
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
		put_error_exit("dup2", "dup failed");
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
