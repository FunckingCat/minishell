#ifndef BUILTIN_H
# define BUILTIN_H

# include "../env/env.h"
# include "../constants.h"

int		cmd_env(char **args, t_env *env);
int		cmd_unset(char **args, t_env *env);
int		cmd_export(char **args, t_env *env);
int		cmd_pwd(char **args, t_env *env);
int		cmd_cd(char **args, t_env *env);
int		cmd_echo(char **args, t_env *env);

int		is_builtin(char *cmd);
void	run_builtin(char *cmd, char **args, t_env *env);

int		is_no_fork(char *cmd);
void	run_no_fork(char *cmd, char **args, t_env *env);

void	check_args(char **args);
void	clean_split(char **new_var);

#endif