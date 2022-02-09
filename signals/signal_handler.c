# include "../minishell.h"
# include <readline/readline.h>
# include <readline/history.h>

void handler(int sig)
{
	
	if (sig == SIGINT)
	{
		ft_putstr_fd("\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void tty_mask(void)
{
	struct termios sterm;
	tcgetattr(0, &sterm);
	sterm.c_lflag &= ~ECHOCTL;
	tcsetattr(0, 0, &sterm);
	signal(SIGQUIT, SIG_IGN);
}