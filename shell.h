#ifndef SHELL_H
#define SHELL_H

# include <sys/wait.h>
# include "./env/env.h"
# include "./redirect/redirect.h"

typedef struct s_cmd
{
	char	*full;
	char	*cmd;
	char	*args;
	int		in;
	int		out;
	t_redirect *left;
	t_redirect *right;
	pid_t	pid;
}	t_cmd;

typedef struct s_shell
{
	int		cmds;
	t_cmd	*cmds_arr;
	t_env	*env;
}	t_shell;

#endif