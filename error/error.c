#include "error.h"

int	put_error(char *module, char *text)
{
	printf(RED"%s: "NONE"%s\n", module, text);
	return (1);
}

int	put_error_status(char *module, char *text, int st)
{
	printf(RED"%s: "NONE"%s\n", module, text);
	return (st);
}

void	*put_error_null(char *module, char *text)
{
	printf(RED"%s: "NONE"%s\n", module, text);
	return (NULL);
}