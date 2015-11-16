#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;

	if ((list = malloc(sizeof(*list))) != NULL)
	{
		if (content == NULL)
		{
			list->content = NULL;
			list->content_size = 0;
			list->next = NULL;
		}
		else
		{
			list->content = content;
			list->content_size= content_size;
			list->next = NULL;
		}
		return (list);
	}
	return (NULL);
}
