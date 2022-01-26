#include "redirect.h"

int	read_loop(t_redirect *this, int *pip)
{
	char	*line;

	while (1)
	{
		ft_putstr_fd(GREEN "> " NONE, 1);
		line = get_next_line(0);
		if (!line)
		{
			close(pip[1]);
			return (1);
		}
		if (!ft_strcmp(line, this->file))
		{
			free(line);
			break ;
		}
		else
		{
			ft_putstr_fd(line, pip[1]);
			ft_putstr_fd("\n", pip[1]);
		}
		free(line);
	}
	return (0);
}

int	read_multiline(t_redirect *this)
{
	int		pip[2];

	if (pipe(pip) == -1)
		return (put_error("pipe", "failed create a pipe"));
	this->fd = pip[0];
	if (read_loop(this, pip))
		return (put_error(RD, "failed to read input"));
	close(pip[1]);
	return (0);
}

int	open_out(t_redirect *this)
{
	if (!access(this->file, ACCESS_EXIST))
	{
		if (access(this->file, ACCESS_WRITE))
			return (put_error(RD, RD_FD_PD));
	}
	if (this->type == RD_OUT)
		this->fd = open(this->file, O_TRUNC | O_WRONLY | O_CREAT, 0644);
	else if (this->type == RD_DOUT)
		this->fd = open(this->file, O_APPEND | O_WRONLY | O_CREAT, 0644);
	if (this->fd == -1)
		return (put_error(RD, RD_FD_FC));
	return (0);
}

int	rd_open_fd(t_redirect *this)
{
	if (this->type == RD_IN)
	{
		if (access(this->file, ACCESS_EXIST))
			return (put_error(RD, RD_FD_NF));
		else if (access(this->file, ACCESS_READ))
			return (put_error(RD, RD_FD_PD));
		this->fd = open(this->file, O_RDONLY);
		if (this->fd == -1)
			return (put_error(RD, RD_FD_FR));
		return (0);
	}
	else if (this->type == RD_OUT || this->type == RD_DOUT)
		return (open_out(this));
	else
		return (read_multiline(this));
	return (0);
}

t_redirect	*new_redirect(char *str)
{
	t_redirect	*this;

	this = malloc(sizeof(t_redirect));
	if (str[0] == '<' && str[1] == '<')
		this->type = RD_DIN;
	else if (str[0] == '<')
		this->type = RD_IN;
	else if (str[0] == '>' && str[1] == '>')
		this->type = RD_DOUT;
	else if (str[0] == '>')
		this->type = RD_OUT;
	else
	{
		free(this);
		return (NULL);
	}
	while (ft_strchr("><", *str))
		str++;
	while (ft_strchr(" ", *str))
		str++;
	this->file = ft_strdup(str);
	if (!this->file || rd_open_fd(this))
		return (free_redirect(this));
	return (this);
}
