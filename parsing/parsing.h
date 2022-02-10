/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:34:56 by david             #+#    #+#             */
/*   Updated: 2022/02/10 18:34:57 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../libft/libft.h"
# include "../constants.h"
# include "../env/env.h"
# include "../command/command.h"
# include "../error/error.h"
# include "../redirect/redirect.h"

# define RCH 13

char	**parse_pipes(char *cmd);
int		parse_redirects(t_cmd *cmd);
char	*parse_abs_path(t_env *env, char *path);
char	*parse_cmd_name(char	*full);
char	*parse_beautify(char	*str);
char	*parse_global(char *cmd, t_env *env);
int		parse_command(t_cmd *cmd, t_env *env);

char	*skip_quotes(char *cmd);

#endif