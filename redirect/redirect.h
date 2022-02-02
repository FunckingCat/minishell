#ifndef REDIRECT_H
# define REDIRECT_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../error/error.h"
# include "../constants.h"
# include "../libft/libft.h"

# define ACCESS_EXIST	00
# define ACCESS_READ	04
# define ACCESS_WRITE	02

typedef struct s_redirect
{
	size_t	type;
	char	*file;
	int		fd;
}	t_redirect;

char		*get_next_line(int fd);
t_redirect	*new_redirect(char *str);
t_redirect	*free_redirect(t_redirect *this);

int	read_multiline(t_redirect *this);

#endif