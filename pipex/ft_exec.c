#include "pipex.h"

char	*full_path(char *path, char *name)
{
	char	*tmp;
	char	*res;

	if (path[ft_strlen(path) - 1] != '/')
	{
		tmp = ft_strjoin(path, "/");
		res = ft_strjoin(tmp, name);
		return (res);
	}
	return (ft_strjoin(path, name));
}

void	run(t_shell *shell, t_cmd *cmd)
{
	char	**path;
	int		i;
	int		status;
	DIR		*dr;

	i = 0;
	if (!cmd->cmd)
		exit(0);
	if (is_builtin(cmd->cmd))
		run_builtin(cmd, shell->env);
	if (!ft_strcmp(ft_strtrim(cmd->cmd, " \t"), EXIT))
		exit(0);
	path = ft_split(env_get(PATH, shell->env), ':');
	if (cmd->full_path[0] == '/')
	{
		dr = opendir(cmd->full_path);
		if (dr)
		{
			closedir(dr);
			put_ext_error_exit(MINISHELL, cmd->full_path, IS_DIR, 126);
		}
		status = execve(cmd->full_path, cmd->args, shell->env->vars);
		put_error_exit(cmd->cmd, strerror(errno), 126);

	}
	while (path[i] != NULL)
	{
		execve(full_path(path[i], cmd->cmd), cmd->args, shell->env->vars);
		i++;
	}
	put_error_exit(cmd->cmd, CMD_NF, 127);
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
		put_error_exit(DUP, DUP_FAIL, 1);
	close_descriptors(shell);
	run(shell, cmd);
}

int  fork_proc(t_shell *shell)
{
	int  i;

	i = 0;
	while (i < shell->cmds)
	{
		shell->cmds_arr[i]->pid = fork();
		if (shell->cmds_arr[i]->pid == -1)
			put_error(FORK, FORK_FAIL);
		else if (shell->cmds_arr[i]->pid == 0)
			exec(shell->cmds_arr[i], shell);
		signal(SIGINT, sig_int_proc);
		signal(SIGQUIT, sig_int_proc);
		shell->pid_c = shell->cmds_arr[i]->pid;
		i++;
	}
	return (0);
}