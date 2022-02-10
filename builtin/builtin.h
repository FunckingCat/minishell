/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:33:16 by david             #+#    #+#             */
/*   Updated: 2022/02/10 18:33:17 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "../env/env.h"
# include "../command/command.h"
# include "../constants.h"

int	cmd_env(char **args, t_env *env);
int	cmd_unset(char **args, t_env *env);
int	cmd_export(char **args, t_env *env);
int	cmd_pwd(char **args, t_env *env);
int	cmd_cd(char **args, t_env *env);
int	cmd_echo(char **args, t_env *env);

int	is_builtin(char *cmd);
int	run_builtin(t_cmd *cmd, t_env *env);
int	is_no_fork(char *cmd);
int	run_no_fork(t_cmd *cmd, t_env *env);

int	check_amount(char **args);
int	check_name(char *arg);

#endif