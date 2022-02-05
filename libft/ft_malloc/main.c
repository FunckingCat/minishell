#include "ft_malloc.h"

int main () 
{
	char *str;

	str = ft_malloc(sizeof(char) * 10);
	printf("NEW %p\n", str);
	// str = ft_malloc(sizeof(char) * 10);
	// printf("NEW %p\n", str);
	// str = ft_malloc(sizeof(char) * 10);
	// printf("NEW %p\n", str);
	// str = ft_malloc(sizeof(char) * 10);
	// printf("NEW %p\n", str);
	ft_free();
}