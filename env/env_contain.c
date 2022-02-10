/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_contain.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:33:54 by david             #+#    #+#             */
/*   Updated: 2022/02/10 18:49:11 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int	env_contain(char *name, t_env *env)
{
	int	i;

	i = 0;
	if (!name || !env || !env->vars)
	{
		put_error(ENV, ENV_NO_PAR);
		return (-1);
	}
	while (i < env->length && env->vars[i])
	{
		if (ft_strncmp(env->vars[i], name, ft_strlen(name)) == 0
			&& env->vars[i][ft_strlen(name)] == '=')
			return (1);
		i++;
	}
	return (0);
}
