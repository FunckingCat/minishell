#ifndef REDIRECT_H
# define REDIRECT_H

# include "../minishell.h"

# define RD			"redirect"
# define RD_FAIL	"invalid params"
# define RD_FD_NF	"No such file or directory"
# define RD_FD_PD	"Permission denied"
# define RD_FD_FR	"File read failed"
# define RD_FD_FC	"File create failed"

# define ACCESS_EXIST	00
# define ACCESS_READ	04
# define ACCESS_WRITE	02

typedef struct s_redirect
{
	size_t	type;
	char	*file;
	int		fd;
}	t_redirect;

t_redirect	*new_redirect(char *str);
t_redirect	*free_redirect(t_redirect *this);

#endif