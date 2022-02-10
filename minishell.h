/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:36:24 by david             #+#    #+#             */
/*   Updated: 2022/02/10 18:36:25 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <signal.h>
# include <termios.h>

# include "./constants.h"
# include "./libft/libft.h"
# include "./error/error.h"
# include "./shell/shell.h"
# include "./env/env.h"
# include "./redirect/redirect.h"
# include "./parsing/parsing.h"
# include "./builtin/builtin.h"
# include "./signals/signals.h"

int		pipex(t_shell *shell);

#endif