/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_ext.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:34:13 by david             #+#    #+#             */
/*   Updated: 2022/02/10 18:34:14 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

int	put_ext_error(char *module, char *obj, char *text)
{
	ft_putstr_fd(module, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(obj, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(text, 2);
	ft_putstr_fd("\n", 2);
	return (1);
}

int	put_ext_error_status(char *module, char *obj, char *text, int st)
{
	ft_putstr_fd(module, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(obj, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(text, 2);
	ft_putstr_fd("\n", 2);
	return (st);
}

void	*put_ext_error_null(char *module, char *obj, char *text)
{
	ft_putstr_fd(module, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(obj, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(text, 2);
	ft_putstr_fd("\n", 2);
	return (NULL);
}

int	put_ext_error_exit(char *module, char *obj, char *text, int st)
{
	ft_putstr_fd(module, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(obj, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(text, 2);
	ft_putstr_fd("\n", 2);
	ft_free();
	exit(st);
}
