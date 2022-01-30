#ifndef COMMAND_H
# define COMMAND_H

#include "../redirect/redirect.h"
#include "../error/error.h"
#include "../constants.h"

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

t_cmd	*new_cmd(char	*cmd);
t_cmd	*free_cmd(t_cmd *cmd);

#endif