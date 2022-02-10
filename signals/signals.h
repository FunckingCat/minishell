#ifndef SIGNALS_H
# define SIGNALS_H

# include <signal.h>
# include <unistd.h>
# include "../shell/shell.h"
# include "../libft/libft.h"
# include "../constants.h"

int		check_int_skip(t_shell *shell, char *read);
int		check_exit_ctrl_d(char *read);
void	sig_int_empty(int signum);
void	sig_int_proc(int signum);

#endif