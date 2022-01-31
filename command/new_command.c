#include "command.h"

t_cmd	*new_cmd(char	*cmd)
{
	t_cmd	*res;

	printf(PURPLE "new CMD: %s\n" NONE, cmd);
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
		free(cmd);
	}
	return (NULL);
}

int	add_redirect(t_cmd *cmd, char *redirect)
{
	t_redirect *new;

	printf(PURPLE "new RD: %s\n" NONE, redirect);
	new = new_redirect(redirect);
	if (!new)
		return (1);
	if (new->type == RD_IN || new->type == RD_DIN)
	{
		if (cmd->left == NULL && cmd->in > 2)
		 	close(cmd->in);
		free_redirect(cmd->left);
		cmd->left = new;
	}
	else
	{
		if (cmd->right == NULL && cmd->out > 2)
		 	close(cmd->out);
		free_redirect(cmd->right);
		cmd->right = new;
	}
	if (cmd->left)
		cmd->in = cmd->left->fd;
	if (cmd->right)
		cmd->out = cmd->right->fd;
	return (0);
}