/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:33:32 by david             #+#    #+#             */
/*   Updated: 2022/02/10 18:33:33 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	check_name(char *arg)
{
	int	i;

	i = 0;
	if (ft_strlen(arg) == 0)
		return (0);
	if (!ft_isalpha(arg[0]))
		return (1);
	while (arg[i] != '\0')
	{
		if (!ft_isalnum(arg[i]) && arg[i] != '_')
			return (1);
		i++;
	}
	return (0);
}

int	set_element(t_env *env, char *arg)
{
	char	*name;
	char	*value;

	if (arg[0] == '=')
		return (put_ext_error(EXP, arg, EXP_NOT_VALID));
	if (!ft_strchr(arg, '='))
	{
		name = ft_strtrim(arg, " ");
		value = ft_strdup("");
	}
	else
	{
		name = ft_substr(arg, 0, ft_strchr(arg, '=') - arg);
		value = ft_strtrim(ft_strchr(arg, '=') + 1, " ");
	}
	if (check_name(name))
		return (put_ext_error(EXP, name, EXP_NOT_VALID));
	return (env_set(name, value, env));
}

int	cmd_export(char **args, t_env *env)
{
	int	i;
	int	stat;

	i = 0;
	stat = 0;
	while (args && args[i])
	{
		if (set_element(env, args[i]) == 1)
			stat = 1;
		i++;
	}
	return (stat);
}
