#ifndef SHELL_H
# define SHELL_H

# include "../env/env.h"
# include "../command/command.h"

typedef struct s_shell
{
	int		exit;
	int		exit_status;
	int		cmds;
	t_cmd	**cmds_arr;
	t_env	*env;
}	t_shell;

int		init_shell(t_shell *shell, char **envp);
int		shell_middle_clean(t_shell *shell);
int		shell_full_clean(t_shell *shell);
void	handler(int sig);
void	tty_mask(void);

#endif