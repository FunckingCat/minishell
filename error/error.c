#include "error.h"

int	put_error(char *module, char *text)
{
	printf(RED"%s: "NONE"%s\n", module, text);
	return (1);
}