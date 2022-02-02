#ifndef COMMAND_H
# define COMMAND_H

#include "../redirect/redirect.h"
#include "../error/error.h"
#include "../constants.h"

typedef struct s_cmd
{
	char	*input;
	char	*cmd;
	char	*args;
	char	*full_path;
	int		in;
	int		out;
	t_redirect *left;
	t_redirect *right;
	pid_t	pid;
}	t_cmd;

t_cmd	*new_cmd(char	*cmd);
t_cmd	*free_cmd(t_cmd *cmd);
int		add_redirect(t_cmd *cmd, char *redirect);

#endif