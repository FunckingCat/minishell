#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	printf("Hello world!!\n");
	pipex(argc, argv, envp);
	return (0);
}