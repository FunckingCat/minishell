#include "ft_malloc.h"

int	add(void *ptr)
{
	void		**new;
	size_t		i;

	new = malloc(sizeof(void *) * (g_heap.count + 1));
	if (!new)
		return (0);
	i = 0;
	while (i < g_heap.count)
	{
		new[i] = g_heap.ptrs[i];
		i++;
	}
	new[g_heap.count] = ptr;
	g_heap.count++;
	if (g_heap.ptrs)
		free(g_heap.ptrs);
	g_heap.ptrs = new;
	return (1);
}

void	*ft_malloc(size_t size)
{
	void	*ptr;

	if (!g_heap.count)
	{
		g_heap.count = 0;
		g_heap.ptrs = NULL;
	}
	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	if (add(ptr))
		return (ptr);
	free(ptr);
	return (NULL);
}

void	ft_free(void)
{
	size_t	i;

	i = 0;
	while (i < g_heap.count)
		free(g_heap.ptrs[i++]);
	free(g_heap.ptrs);
}
