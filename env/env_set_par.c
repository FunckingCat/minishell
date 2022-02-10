/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_set_par.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:34:05 by david             #+#    #+#             */
/*   Updated: 2022/02/10 18:48:33 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int	fill_new_vars(t_env *env, char *str, char **extra)
{
	int	i;

	i = 0;
	env->vars = ft_malloc(sizeof(char *) * (env->length + 2));
	if (!env->vars)
		return (1);
	while (i < env->length)
	{
		env->vars[i] = extra[i];
		i++;
	}
	env->vars[i] = str;
	env->vars[++i] = NULL;
	return (0);
}

void	env_reset(t_env *env, char *name, char *str)
{
	int		i;
	char	*old;

	i = 0;
	while (i < env->length)
	{
		if (env->vars[i])
		{
			if (ft_strncmp(env->vars[i], name, ft_strlen(name)) == 0
				&& env->vars[i][ft_strlen(name)] == '=')
			{
				old = env->vars[i];
				env->vars[i] = str;
			}
		}
		i++;
	}
}

int	env_set(char *name, char *content, t_env *env)
{
	char	**extra;
	char	*str;
	char	*str1;

	if (!name || !env || !env->vars)
		return (put_error(ENV, ENV_NO_PAR));
	str1 = ft_strjoin(name, "=");
	str = ft_strjoin(str1, content);
	if (env_contain(name, env) == 0)
	{
		extra = env->vars;
		if (fill_new_vars(env, str, extra) == 1)
			return (put_error(ENV, ENV_MALLOC));
		env->length++;
	}
	else
		env_reset(env, name, str);
	return (0);
}
