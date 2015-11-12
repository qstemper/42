#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*ptr;

	if ((ptr = malloc(sizeof(size_t) * size)) != NULL)
	{
		ptr = 0;
		return (ptr);
	}
	return (NULL);
}
