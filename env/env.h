#ifndef ENV_H
# define ENV_H

# include "../libft/libft.h"
# include "../error/error.h"

# define ENV "env"
# define ENV_MALLOC "malloc error" 
# define ENV_NO_PAR "no parameters"

typedef struct s_env
{
	size_t	length;
	char	**vars;
}		t_env;

t_env	*env_init(char **envp);
char	*env_get(char *name, t_env *envi);
int		env_contain(char *name, t_env *envi);
int		env_set(char *name, char *content, t_env *envi);
int		env_delete(char *name, t_env *envi);
t_env	*env_free(t_env *envi);

t_env	*malloc_return_pointer(t_env *envi);
int		malloc_return_int(void);

#endif