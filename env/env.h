#ifndef ENV_H
#define ENV_H

#include "../minishell.h"

# define ENV "env"
# define ENV_MALLOC "malloc error" 
typedef struct s_env
{
	char **env;
} t_env;

int	get_memory_env(char **envp, t_env *envi, int count);
t_env *init_env(char **envp);
char	*env_get(char *name, t_env *envi);



//Функция инициализации принимает массив строк                   --------DONE---------

//Здесь еще приходит указатель на структуру
//Функция получения переменной по имени char *func(char *);
//Функция создания переменной 
//Функция проверки наличия переменной int isInEnv(char *);
//Функция удаления перемнной из env
//Функция  free

#endif