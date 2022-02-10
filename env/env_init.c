/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:34:03 by david             #+#    #+#             */
/*   Updated: 2022/02/10 18:34:04 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int	get_memory_env(char **envp, t_env *envi)
{
	int	i;

	i = 0;
	while (i < envi->length && envp[i])
	{
		envi->vars[i] = ft_strdup(envp[i]);
		if (envi->vars[i] == NULL)
			return (1);
		i++;
	}
	envi->vars[i] = NULL;
	return (0);
}

t_env	*env_init(char **envp)
{
	t_env	*envi;
	int		count;

	count = 0;
	while (envp[count])
		count++;
	envi = ft_malloc(sizeof(t_env));
	if (!envi)
		return (put_error_null(ENV, ENV_MALLOC));
	envi->length = count;
	envi->vars = ft_malloc(sizeof(char *) * (envi->length + 1));
	if (!envi->vars)
		return (put_error_null(ENV, ENV_MALLOC));
	if (get_memory_env(envp, envi))
		return (put_error_null(ENV, ENV_MALLOC));
	env_set("?", "0", envi);
	return (envi);
}
