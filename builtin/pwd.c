/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:33:34 by david             #+#    #+#             */
/*   Updated: 2022/02/11 14:36:26 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	cmd_pwd(char **args, t_env *env)
{
	char	*res;

	if (!env || !env->vars)
		return (put_error("pwd", "env is corrupted"));
	(void)args;
	res = env_get("PWD", env);
	if (!res)
		return (1);
	ft_putstr_fd(res, 1);
	write (1, "\n", 1);
	return (0);
}
