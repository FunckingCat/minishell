#include "pipex.h"

// char	*full_path(char *path, char *name)
// {
// 	char	*tmp;
// 	char	*res;

// 	if (name[0] == '/')
// 		return (name);
// 	if (path[ft_strlen(path) - 1] != '/')
// 	{
// 		tmp = ft_strjoin(path, "/");
// 		res = ft_strjoin(tmp, name);
// 		free(tmp);
// 		return (res);
// 	}
// 	return (ft_strjoin(path, name));
// }

// void	run(char *comand, char **envp)
// {
// 	char	**ac;
// 	char	**path;
// 	int		i;
// 	int		j;

// 	i = 0;
// 	j = 0;
// 	ac = ft_split(comand, ' ');
// 	while (ft_strncmp("PATH", envp[j], 4))
// 		j++;
// 	while (*(envp[j]) != '=')
// 		envp[j]++;
// 	envp[j]++;
// 	path = ft_split(envp[j], ':');
// 	while (path[i] != NULL)
// 	{
// 		execve(full_path(path[i], ac[0]), ac, envp);
// 		i++;
// 	}
// 	error(ac[0], "command not found");
// }

// void	close_descriptors(t_env *env)
// {
// 	int	i;

// 	i = 0;
// 	while (i < env->cmds)
// 	{
// 		if (env->commands[i].in != 0)
// 			close(env->commands[i].in);
// 		if (env->commands[i].out != 1)
// 			close(env->commands[i].out);
// 		i++;
// 	}
// }

void	exec(t_cmd *cmd, t_shell *shell)
{
	sleep(3);
	printf(GREEN "%s\n" NONE, cmd->full);
	exit(0);
	// if (dup2(cmd->in, 0) == -1 || dup2(cmd->out, 1) == -1)
	// 	error("dup2", "dup failed");
	// close_descriptors(env);
	// run(cmd->arg, env->ep);
}

void	fork_proc(t_shell *shell)
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
}
