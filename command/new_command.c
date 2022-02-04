#include "command.h"

t_cmd	*new_cmd(char	*cmd)
{
	t_cmd	*res;

	res = malloc(sizeof(t_cmd));
	res->input = cmd;
	res->cmd = NULL;
	res->args = NULL;
	res->full_path = NULL;
	res->in = 0;
	res->out = 1;
	res->left = NULL;
	res->right = NULL;
	return (res);
}

void	free_char_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

t_cmd	*free_cmd(t_cmd *cmd)
{
	if (cmd)
	{
		if (cmd->input)
			free(cmd->input);
		if (cmd->full_path)
			free(cmd->full_path);
		if (cmd->args)
			free_char_arr(cmd->args);
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