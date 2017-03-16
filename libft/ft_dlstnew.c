#include "libft.h"

t_dlist			*ft_dlstnew(const void *content, size_t content_size)
{
	t_dlist		*new;

	if (!(new = (t_dlist *)malloc(sizeof(t_dlist))))
		return (NULL);
	new->n = NULL;
	new->p = NULL;
	if (!content)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		if (!(new->content = malloc(content_size)))
		{
			free(new);
			return (NULL);
		}
		new->content = ft_memcpy(new->content, content, content_size);
		new->content_>size = content_size
	}
	return (new);
}
