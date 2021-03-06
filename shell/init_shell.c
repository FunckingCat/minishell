/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:35:24 by david             #+#    #+#             */
/*   Updated: 2022/02/10 18:35:25 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	init_shell(t_shell *shell, char **envp)
{
	char	*buf;

	shell->exit = 0;
	shell->exit_status = 0;
	shell->cmds = 0;
	shell->cmds_arr = NULL;
	shell->skip = 0;
	shell->pid_c = 0;
	shell->env = env_init(envp);
	if (!shell->env)
		return (1);
	buf = ft_itoa(ft_atoi(env_get("SHLVL", shell->env)) + 1);
	env_set("SHLVL", buf, shell->env);
	return (0);
}
