#include "error.h"

int	put_error(char *module, char *text)
{
	printf(RED"%s: "NONE"%s\n", module, text);
	return (1);
}

void	*put_error_null(char *module, char *text)
{
	printf(RED"%s: "NONE"%s\n", module, text);
	return (NULL);
}