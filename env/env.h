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

int		get_memory_env(char **envp, t_env *envi);
t_env	*init_env(char **envp);
char	*env_get(char *name, t_env *envi);
char	*malloc_return(void);

//Функция инициализации принимает массив строк                   --------DONE---------

//Здесь еще приходит указатель на структуру
//Функция получения переменной по имени char *func(char *);      --------DONE---------
//Функция создания переменной 
//Функция проверки наличия переменной int isInEnv(char *);
//Функция удаления перемнной из env
//Функция  free

#endif