# include "builtin.h"

int is_builtin(char *name)
{
    if (ft_strcmp(name, "cd") == 0)
        return (1);
    else if (ft_strcmp(name, "pwd") == 0)
        return (1);
    else if (ft_strcmp(name, "unset") == 0)
        return (1);
    else if (ft_strcmp(name, "export") == 0)
        return (1);
    else if (ft_strcmp(name, "echo") == 0)
        return (1);
    else if (ft_strcmp(name, "env") == 0)
        return (1);
    return (0);
}

void exit_clean(t_env *envi, char *name, char *arg)
{
    if (envi)
        env_free(envi);
    if (name)
        free(name);
    if (arg)
        free(name);
}

void manage_builtin(char *name, char *arg, t_env *envi)
{
    int res;

    res = -1;
    if (ft_strcmp(name, "cd") == 0)
        res = cd(arg, envi);
    else if (ft_strcmp(name, "pwd") == 0)
        res = pwd(envi);
    else if (ft_strcmp(name, "unset") == 0)
        res = unset(envi, arg);
    else if (ft_strcmp(name, "export") == 0)
        res = export(envi, arg);
    else if (ft_strcmp(name, "echo") == 0)
        res = echo(arg);
    else if (ft_strcmp(name, "env") == 0)
        {
            if (arg)
                res = put_error(ENV, ENV_NO_FILE);
            else
                res = env(envi);
        }
    exit_clean(envi, name, arg);
    if (res != -1)
        exit(res);
}