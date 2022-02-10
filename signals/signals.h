/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 22:11:48 by rusty             #+#    #+#             */
/*   Updated: 2022/02/09 04:03:26 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

# include <signal.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../constants.h"
# include "../minishell.h"

void	sig_int_empty(int signum);
void	sig_int_proc(int signum);

#endif