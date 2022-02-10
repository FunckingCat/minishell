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
	int		skip;
	pid_t	pid_c;
}	t_shell;

int	init_shell(t_shell *shell, char **envp);

#endif