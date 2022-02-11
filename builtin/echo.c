/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:33:26 by david             #+#    #+#             */
/*   Updated: 2022/02/10 18:33:26 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	print_args(char **args, int option)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (i == 0 && option == 0)
		{
			ft_putstr_fd(args[i], 1);
			write (1, " ", 1);
		}
		else if (i != 0)
		{
			if (i != 0)
				ft_putstr_fd(args[i], 1);
			if (args[i + 1])
				write (1, " ", 1);
		}
		i++;
	}
}

int	cmd_echo(char **args, t_env *env)
{
	int	option;

	option = 0;
	(void)env;
	if (ft_strcmp(args[0], "-n") == 0)
		option = 1;
	print_args(args, option);
	if (option != 1)
		write(1, "\n", 1);
	return (0);
}
