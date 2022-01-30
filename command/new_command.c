#include "command.h"

t_cmd	*new_cmd(char	*cmd)
{
	t_cmd	*res;

	res = malloc(sizeof(t_cmd));
	res->full = cmd;
	res->cmd = NULL;
	res->args = NULL;
	res->in = 0;
	res->out = 1;
	res->left = NULL;
	res->right = NULL;
}

t_cmd	*free_cmd(t_cmd *cmd)
{
	if (cmd)
	{
		if (cmd->full)
			free(cmd->full);
		if (cmd->cmd)
			free(cmd->cmd);
		if (cmd->args)
			free(cmd->args);
		if (cmd->left)
			free_redirect(cmd->left);
		if (cmd->right)
			free_redirect(cmd->right);
	}
	return (NULL);
}