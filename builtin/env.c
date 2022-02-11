/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:33:29 by david             #+#    #+#             */
/*   Updated: 2022/02/11 14:35:54 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	cmd_env(char **args, t_env *env)
{
	size_t	i;

	i = 0;
	if (!env || !env->vars)
		return (put_error(ENV, NO_ENV));
	if (args && args[i] != NULL)
		return (put_error(ENV, CD_MN_ARGS));
	while (i < env->length)
	{
		ft_putstr_fd(env->vars[i], 1);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
