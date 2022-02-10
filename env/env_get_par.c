/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_get_par.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:34:00 by david             #+#    #+#             */
/*   Updated: 2022/02/10 18:34:01 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

char	*env_get(char *name, t_env *envi)
{
	int		i;

	i = 0;
	if (!name || !envi || !envi->vars)
	{
		put_error(ENV, ENV_NO_PAR);
		return (NULL);
	}
	while (envi->vars[i])
	{
		if (ft_strncmp(envi->vars[i], name, ft_strlen(name)) == 0
			&& envi->vars[i][ft_strlen(name)] == '=')
			return (ft_strdup(&envi->vars[i][ft_strlen(name) + 1]));
		i++;
	}
	return (ft_strdup(" "));
}
