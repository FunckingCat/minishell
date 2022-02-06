#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/wait.h>
# include <errno.h>
# include "../libft/libft.h"
# include "../constants.h"
# include "../shell/shell.h"
# include "../error/error.h"
# include "../builtin/builtin.h"
# include "../parsing/parsing.h"

int	fork_proc(t_shell *shell);

#endif