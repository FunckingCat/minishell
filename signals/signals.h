/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 22:11:48 by rusty             #+#    #+#             */
/*   Updated: 2022/02/10 14:52:06 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

# include <signal.h>
# include <unistd.h>
# include "../shell/shell.h"
# include "../libft/libft.h"
# include "../constants.h"

void	sig_int_empty(int signum);
void	sig_int_proc(int signum);

#endif