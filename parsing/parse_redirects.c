/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redirects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:34:53 by david             #+#    #+#             */
/*   Updated: 2022/02/10 18:34:54 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	calc_red_len(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i] && ft_strchr("<>", cmd[i]))
		i++;
	while (cmd[i] == ' ')
		i++;
	while (cmd[i] && !ft_strchr("<> ", cmd[i]))
		i++;
	return (i);
}

int	parse_redirects(t_cmd *cmd)
{
	int			i;
	int			len;
	char		*tmp;

	i = 0;
	while ((cmd->input)[i])
	{
		if (cmd->input[i] == '\'' || cmd->input[i] == '\"')
			i = skip_quotes(cmd->input + i) - cmd->input;
		if (ft_strchr("<>", cmd->input[i]))
		{
			len = calc_red_len(cmd->input + i);
			tmp = ft_malloc(len + 1);
			ft_strlcpy(tmp, cmd->input + i, len + 1);
			if (add_redirect(cmd, tmp))
				return (1);
			ft_memset(cmd->input + i, RCH, len);
			i += len;
		}
		else
			i++;
	}
	cmd->input = ft_remove_char(cmd->input, RCH);
	return (0);
}
