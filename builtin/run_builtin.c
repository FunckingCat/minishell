/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:33:37 by david             #+#    #+#             */
/*   Updated: 2022/02/10 18:33:37 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	is_builtin(char *cmd)
{
	if (ft_strcmp(cmd, "cd") == 0)
		return (1);
	else if (ft_strcmp(cmd, "pwd") == 0)
		return (1);
	else if (ft_strcmp(cmd, "unset") == 0)
		return (1);
	else if (ft_strcmp(cmd, "export") == 0)
		return (1);
	else if (ft_strcmp(cmd, "echo") == 0)
		return (1);
	else if (ft_strcmp(cmd, "env") == 0)
		return (1);
	return (0);
}

int	run_builtin(t_cmd *cmd, t_env *env)
{
	int	status;

	status = 0;
	if (ft_strcmp(cmd->cmd, "cd") == 0)
		status = cmd_cd(cmd->args + 1, env);
	else if (ft_strcmp(cmd->cmd, "pwd") == 0)
		status = cmd_pwd(cmd->args + 1, env);
	else if (ft_strcmp(cmd->cmd, "unset") == 0)
		status = cmd_unset(cmd->args + 1, env);
	else if (ft_strcmp(cmd->cmd, "export") == 0)
		status = cmd_export(cmd->args + 1, env);
	else if (ft_strcmp(cmd->cmd, "echo") == 0)
		status = cmd_echo(cmd->args + 1, env);
	else if (ft_strcmp(cmd->cmd, "env") == 0)
		status = cmd_env(cmd->args + 1, env);
	ft_free();
	exit(status);
}

int	is_no_fork(char *cmd)
{
	if (ft_strcmp(cmd, "cd") == 0)
		return (1);
	else if (ft_strcmp(cmd, "unset") == 0)
		return (1);
	else if (ft_strcmp(cmd, "export") == 0)
		return (1);
	return (0);
}

int	run_no_fork(t_cmd *cmd, t_env *env)
{
	int	status;

	status = 0;
	if (ft_strcmp(cmd->cmd, "cd") == 0)
		status = cmd_cd(cmd->args + 1, env);
	else if (ft_strcmp(cmd->cmd, "unset") == 0)
		status = cmd_unset(cmd->args + 1, env);
	else if (ft_strcmp(cmd->cmd, "export") == 0)
		status = cmd_export(cmd->args + 1, env);
	env_set("_", cmd->cmd, env);
	env_set("?", ft_itoa(status), env);
	return (status);
}
