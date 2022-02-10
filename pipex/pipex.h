/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:35:11 by david             #+#    #+#             */
/*   Updated: 2022/02/10 18:35:12 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <dirent.h>
# include <errno.h>
# include <string.h>
# include "../signals/signals.h"
# include "../libft/libft.h"
# include "../constants.h"
# include "../shell/shell.h"
# include "../error/error.h"
# include "../builtin/builtin.h"
# include "../parsing/parsing.h"

int	fork_proc(t_shell *shell);

#endif