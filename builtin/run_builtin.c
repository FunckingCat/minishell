# include "builtin.h"

int		is_builtin(char *cmd)
{
    if (ft_strcmp(cmd, "cd") == 0)
        return (1);
    else if (ft_strcmp(cmd, "pwd") == 0)
        return (1);
    else if (ft_strcmp(cmd, "unset") == 0)
        return (1);
    else if (ft_strcmp(cmd, "export") == 0)
        return (1);
    else if (ft_strcmp(cmd, "echo") == 0)
        return (1);
    else if (ft_strcmp(cmd, "env") == 0)
        return (1);
    return (0);
}

int run_builtin(char *cmd, char **args, t_env *env)
{
    int status;

    if (ft_strcmp(cmd, "cd") == 0)
        status = cmd_cd(args, env);
    else if (ft_strcmp(cmd, "pwd") == 0)
        status = cmd_pwd(args, env);
    else if (ft_strcmp(cmd, "unset") == 0)
        status = cmd_unset(args, env);
    else if (ft_strcmp(cmd, "export") == 0)
        status = cmd_export(args, env);
    else if (ft_strcmp(cmd, "echo") == 0)
        status = cmd_echo(args, env);
    else if (ft_strcmp(cmd, "env") == 0)
        status = cmd_env(args, env);
    exit(status);
}

int is_no_fork(char *cmd)
{
    if (ft_strcmp(cmd, "cd") == 0)
        return (1);
    else if (ft_strcmp(cmd, "unset") == 0)
        return (1);
    else if (ft_strcmp(cmd, "export") == 0)
        return (1);
    return (0);
}

int run_no_fork(char *cmd, char **args, t_env *env)
{
    int status;

    if (ft_strcmp(cmd, "cd") == 0)
        status = cmd_cd(args, env);
    else if (ft_strcmp(cmd, "unset") == 0)
        status = cmd_unset(args, env);
    else if (ft_strcmp(cmd, "export") == 0)
        status = cmd_export(args, env);
    return (status);
}