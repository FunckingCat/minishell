/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:34:07 by david             #+#    #+#             */
/*   Updated: 2022/02/10 18:48:46 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "../libft/libft.h"
# include "../error/error.h"
# include "../constants.h"

typedef struct s_env
{
	size_t	length;
	char	**vars;
}		t_env;

t_env	*env_init(char **envp);
char	*env_get(char *name, t_env *env);
int		env_contain(char *name, t_env *env);
int		env_set(char *name, char *content, t_env *env);
int		env_delete(char *name, t_env *env);

t_env	*malloc_return_pointer(t_env *env);
int		malloc_return_int(void);

#endif