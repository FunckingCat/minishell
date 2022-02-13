/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_redirect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:35:15 by david             #+#    #+#             */
/*   Updated: 2022/02/10 18:35:16 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirect.h"

t_redirect	*free_redirect(t_redirect *this)
{
	if (this && this->fd)
		close(this->fd);
	return (NULL);
}

int	read_loop(t_redirect *this, int *pip)
{
	char	*line;

	while (1)
	{
		line = readline(REDIRECT);
		if (!line)
			return (0);
		if (!ft_strcmp(line, this->file))
		{
			free(line);
			break ;
		}
		else
		{
			ft_putstr_fd(line, pip[1]);
			ft_putstr_fd("\n", pip[1]);
		}
		free(line);
	}
	return (0);
}

int	read_multiline(t_redirect *this)
{
	int		pip[2];

	if (pipe(pip) == -1)
		return (put_error(PIPE, PIPE_FAIL));
	this->fd = pip[0];
	if (read_loop(this, pip))
		return (put_error(RD, RD_RAD_FL));
	close(pip[1]);
	return (0);
}
