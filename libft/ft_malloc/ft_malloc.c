#include "ft_malloc.h"

int	add(void *ptr)
{
	void		**new;
	size_t		i;

	new = malloc(sizeof(void *) * (heap.count + 1));
	if (!new)
		return (0);
	i = 0;
	while (i < heap.count)
	{
		new[i] = heap.ptrs[i];
		i++;
	}
	new[heap.count] = ptr;
	heap.count++;
	if (heap.ptrs)
		free(heap.ptrs);
	heap.ptrs = new;
	return (1);
}

void	*ft_malloc(size_t size)
{
	void	*ptr;

	if (!heap.count)
	{
		heap.count = 0;
		heap.ptrs = NULL;
	}
	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	if (add(ptr))
		return (ptr);
	free(ptr);
	return (NULL);
}

void	ft_free()
{
	size_t	i;

	i = 0;
	while (i < heap.count)
		free(heap.ptrs[i++]);
	free(heap.ptrs);
}