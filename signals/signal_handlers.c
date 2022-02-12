/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handlers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:35:32 by david             #+#    #+#             */
/*   Updated: 2022/02/11 14:40:33 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"

int	check_exit_ctrl_d(char *read)
{
	if (!read)
	{
		write(1, "exit\n", 6);
		return (1);
	}
	return (0);
}

int	check_int_skip(t_shell *shell, char *read)
{
	if (shell->skip == 1)
	{
		shell->skip = 0;
		free(read);
		return (1);
	}
	return (0);
}

void	sig_int_empty(int signum)
{
	if (signum == SIGINT)
	{
		write(2, "\n\r\0", 3);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	sig_int_proc(int signum)
{
	t_shell	*shell;

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
