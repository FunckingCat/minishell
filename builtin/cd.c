/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:33:20 by david             #+#    #+#             */
/*   Updated: 2022/02/10 18:33:21 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	check_amount(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}

int	cmd_cd(char **args, t_env *env)
{
	char	*buff;
	int		status;

	status = 0;
	if (check_amount(args) == 0)
		return (0);
	if (check_amount(args) > 1)
		return (put_error(CD, CD_MN_ARGS));
	if (chdir(args[0]) == -1)
		return (put_ext_error(CD, args[0], CD_NO_FILE));
	buff = env_get("PWD", env);
	if (!buff)
		return (put_error(CD, MALLOC_ERR));
	if (env_set("OLDPWD", buff, env))
		status = 1;
	buff = getcwd(NULL, 1044480);
	if (!buff)
		return (put_error(CD, MALLOC_ERR));
	if (env_set("PWD", buff, env))
		status = 1;
	free(buff);
	return (status);
}
