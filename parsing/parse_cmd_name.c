/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_name.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:34:43 by david             #+#    #+#             */
/*   Updated: 2022/02/10 18:34:44 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	*parse_cmd_name(char	*full)
{
	char	*res;
	int		i;

	res = ft_strtrim(full, " \t");
	i = ft_strlen(res) - 1;
	while (i > 0 && res[i] != '/')
		i--;
	if (i == 0)
		return (res);
	while (i >= 0)
		res[i--] = RCH;
	return (ft_remove_char(res, RCH));
}
