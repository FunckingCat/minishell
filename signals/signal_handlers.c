/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handlers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 22:12:43 by rusty             #+#    #+#             */
/*   Updated: 2022/02/10 14:48:56 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"

/*
** CTRL-C
*/

void	sig_int_empty(int signum)
{
	if (signum == SIGINT)
	{
		write(2, "\n\r\0", 3);
		// ft_putstr_fd(YELLOW PROMPT NONE, 1);
		// g_shell.skip = 1;
		// signal(SIGINT, sig_int_empty);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	sig_int_proc(int signum)
{
	t_shell *shell;
	
	shell = (t_shell *)g_heap.ptr;
	if (signum == SIGINT)
	{
		kill(shell->pid_c, SIGINT);
		write(1, "\n", 1);
	}
	if (signum == SIGQUIT)
	{
		kill(shell->pid_c, SIGINT);
		write(1, "Quit (core dumped)\n", 19);
		signal(SIGQUIT, SIG_IGN);
	}
}
