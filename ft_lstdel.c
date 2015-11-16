#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*list;

	list = *alst;
	while (list->next)
	{
		ft_lstdelone(&list, (*del));
		list = list->next;
	}
	*alst = NULL;
}
