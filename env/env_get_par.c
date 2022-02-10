/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_get_par.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:34:00 by david             #+#    #+#             */
/*   Updated: 2022/02/10 18:49:04 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

char	*env_get(char *name, t_env *env)
{
	int		i;

	i = 0;
	if (!name || !env || !env->vars)
	{
		put_error(ENV, ENV_NO_PAR);
		return (NULL);
	}
	while (env->vars[i])
	{
		if (ft_strncmp(env->vars[i], name, ft_strlen(name)) == 0
			&& env->vars[i][ft_strlen(name)] == '=')
			return (ft_strdup(&env->vars[i][ft_strlen(name) + 1]));
		i++;
	}
	return (ft_strdup(" "));
}
