# include "builtin.h"

void    print_args(char **args, int option)
{
    int i;

    i = 0;
    while (args[i])
    {
        if (i == 0 && option == 0)
        {
            ft_putstr_fd(args[i], 1);
            write (1, " ", 1);
        }
        else if (i !=0 )
        {
            if (i != 0)
                ft_putstr_fd(args[i], 1);
            if (args[i + 1])
                write (1, " ", 1);
        }
        i++;
    }
}

int echo(char *str)
{
    char **args;
    int option;
    int i;

    option = 0 ;
    if (!str)
        return (0);
    args = ft_split(str, ' ');
    if (!args)
        return (1);
    if (ft_strcmp(args[0], "-n") == 0)
        option = 1;
    print_args(args, option);
    if (option != 1)
        write(1, "\n", 1);
    clean_split(args);
    return (0);
}