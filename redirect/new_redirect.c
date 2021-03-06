/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_redirect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:35:18 by david             #+#    #+#             */
/*   Updated: 2022/02/10 18:35:19 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirect.h"

int	open_out(t_redirect *this)
{
	if (!access(this->file, ACCESS_EXIST))
	{
		if (access(this->file, ACCESS_WRITE))
			return (put_ext_error(RD, this->file, RD_FD_PD));
	}
	if (this->type == RD_OUT)
		this->fd = open(this->file, O_TRUNC | O_WRONLY | O_CREAT, 0644);
	else if (this->type == RD_DOUT)
		this->fd = open(this->file, O_APPEND | O_WRONLY | O_CREAT, 0644);
	if (this->fd == -1)
		return (put_error(RD, RD_FD_FC));
	return (0);
}

int	rd_open_fd(t_redirect *this)
{
	if (this->type == RD_IN)
	{
		if (access(this->file, ACCESS_EXIST))
			return (put_ext_error(RD, this->file, RD_FD_NF));
		else if (access(this->file, ACCESS_READ))
			return (put_ext_error(RD, this->file, RD_FD_PD));
		this->fd = open(this->file, O_RDONLY);
		if (this->fd == -1)
			return (put_ext_error(RD, this->file, RD_FD_FR));
		return (0);
	}
	else if (this->type == RD_OUT || this->type == RD_DOUT)
		return (open_out(this));
	else
		return (read_multiline(this));
	return (0);
}

int	validate_input(char *str)
{
	if (!ft_strchr("<>", *str))
		return (1);
	if (str[0] == '>' && str[1] == '<')
		return (1);
	if (ft_strchr("<>", *str))
		str++;
	if (ft_strchr("<>", *str))
		str++;
	while (*str == ' ')
		str++;
	if (ft_strchr("<>", *str))
		return (1);
	return (0);
}

t_redirect	*new_redirect(char *str)
{
	t_redirect	*this;

	if (validate_input(str))
		return (put_ext_error_null(MINISHELL, str, RD_ERR_T));
	this = ft_malloc(sizeof(t_redirect));
	if (!this)
		return (put_error_null(MINISHELL, MALLOC_ERR));
	if (str[0] == '<' && str[1] == '<')
		this->type = RD_DIN;
	else if (str[0] == '>' && str[1] == '>')
		this->type = RD_DOUT;
	else if (str[0] == '<')
		this->type = RD_IN;
	else
		this->type = RD_OUT;
	while (ft_strchr("><", *str))
		str++;
	while (ft_strchr(" ", *str))
		str++;
	this->file = ft_strdup(str);
	if (!this->file || rd_open_fd(this))
		return (free_redirect(this));
	return (this);
}
