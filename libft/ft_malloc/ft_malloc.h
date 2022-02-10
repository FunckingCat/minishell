#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# include <stdlib.h>
# include <stdio.h>

typedef struct s_heap
{
	size_t	count;
	void	**ptrs;
	void	*ptr;
}	t_heap;

t_heap	g_heap;

void	*ft_malloc(size_t size);
void	ft_free(void);

#endif