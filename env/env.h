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
	char	**env;
}		t_env;

int		get_memory_env(char **envp, t_env *envi, int count);
int		init_env(t_env *envi, char **envp);
char	*env_get(char *name, t_env *envi);
int		check_line(char *name, char *str, char **deffin);
void	init_struct(t_env *envi); // функция для начальной нулевой инициализации структуры

//Функция инициализации принимает массив строк                   --------DONE---------
// Инитить структуру все что в ней изачальн                      --------DONE---------
// спросить про выделение памяти под струткуру отдельно, а не только под ее элемент

//Здесь еще приходит указатель на структуру
//Функция получения переменной по имени char *func(char *);      --------DONE---------
//Функция создания переменной 
//Функция проверки наличия переменной int isInEnv(char *);
//Функция удаления перемнной из env
//Функция  free

#endif