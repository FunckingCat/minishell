#ifndef SHELL_H
# define SHELL_H

# include "../env/env.h"
# include "../command/command.h"

typedef struct s_shell
{
	int		cmds;
	t_cmd	**cmds_arr;
	t_env	*env;
}	t_shell;

#endif