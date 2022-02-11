/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_del.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:33:58 by david             #+#    #+#             */
/*   Updated: 2022/02/11 14:35:37 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	exclude_var(t_env *env, char *name, char **extra)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	while (j < env->length)
	{
		if (ft_strncmp(extra[j], name, ft_strlen(name)) == 0
			&& extra[j][ft_strlen(name)] == '=')
			j++;
		else
		{
			env->vars[i] = extra[j];
			i++;
			j++;
		}
	}
	env->vars[i] = NULL;
	env->length--;
}

int	env_delete(char *name, t_env *env)
{
	char	**extra;

	if (!env || !name || !env->vars)
		return (put_error(ENV, ENV_MALLOC));
	if (env_contain(name, env))
	{
		extra = env->vars;
		env->vars = ft_malloc(sizeof(char *) * (env->length));
		if (!env->vars)
			return (put_error(ENV, ENV_MALLOC));
		exclude_var(env, name, extra);
	}
	return (0);
}
