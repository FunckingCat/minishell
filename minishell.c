#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	while (1)
	{
		char * str = readline(YELLOW PROMPT NONE);
		add_history(str);
		put_error("main", str);
		free(str);
	}
	return (0);
}