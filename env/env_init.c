/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:34:03 by david             #+#    #+#             */
/*   Updated: 2022/02/10 18:49:00 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int	get_memory_env(char **envp, t_env *env)
{
	int	i;

	i = 0;
	while (i < env->length && envp[i])
	{
		env->vars[i] = ft_strdup(envp[i]);
		if (env->vars[i] == NULL)
			return (1);
		i++;
	}
	env->vars[i] = NULL;
	return (0);
}

t_env	*env_init(char **envp)
{
	t_env	*env;
	int		count;

	count = 0;
	while (envp[count])
		count++;
	env = ft_malloc(sizeof(t_env));
	if (!env)
		return (put_error_null(ENV, ENV_MALLOC));
	env->length = count;
	env->vars = ft_malloc(sizeof(char *) * (env->length + 1));
	if (!env->vars)
		return (put_error_null(ENV, ENV_MALLOC));
	if (get_memory_env(envp, env))
		return (put_error_null(ENV, ENV_MALLOC));
	env_set("?", "0", env);
	return (env);
}
