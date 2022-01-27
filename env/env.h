#ifndef ENV_H
# define ENV_H

# include "../minishell.h"
# include "unistd.h"
# include "../libft/libft.h"

# define ENV "env"
# define ENV_MALLOC "malloc error" 
# define ENV_NO_PAR "no parameters"

typedef struct s_env
{
	size_t	length;
	char	**vars; 
}		t_env;

t_env	*init_env(char **envp);
char	*env_get(char *name, t_env *envi);
int		is_contain(char *name, t_env *envi);
int		env_set(char *name, char *content, t_env *envi);
int		env_delet(char *name, t_env *envi);
t_env	*env_free(t_env *envi);


t_env	*malloc_return_pointer(t_env *envi);
int		malloc_return_int(void);

//Функция инициализации принимает массив строк                   --------DONE---------

//Здесь еще приходит указатель на структуру
//Функция получения переменной по имени char *func(char *);      --------DONE---------
//Функция создания переменной									 --------DONE---------
//Функция проверки наличия переменной int isInEnv(char *);       --------DONE---------
//Функция удаления перемнной из env								 --------DONE---------
//Функция  free

#endif