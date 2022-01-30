#include "error.h"

int	put_error(char *module, char *text)
{
	ft_putstr_fd(RED, 2);
	ft_putstr_fd(module, 2);
	ft_putstr_fd(": " NONE, 2);
	ft_putstr_fd(text, 2);
	ft_putstr_fd("\n", 2);
	return (1);
}

int	put_error_status(char *module, char *text, int st)
{
	ft_putstr_fd(RED, 2);
	ft_putstr_fd(module, 2);
	ft_putstr_fd(": " NONE, 2);
	ft_putstr_fd(text, 2);
	ft_putstr_fd("\n", 2);
	return (st);
}

void	*put_error_null(char *module, char *text)
{
	ft_putstr_fd(RED, 2);
	ft_putstr_fd(module, 2);
	ft_putstr_fd(": " NONE, 2);
	ft_putstr_fd(text, 2);
	ft_putstr_fd("\n", 2);
	return (NULL);
}

int	put_error_exit(char *module, char *text)
{
	ft_putstr_fd(RED, 2);
	ft_putstr_fd(module, 2);
	ft_putstr_fd(": " NONE, 2);
	ft_putstr_fd(text, 2);
	ft_putstr_fd("\n", 2);
	exit(0);
}