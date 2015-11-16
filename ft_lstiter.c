#include "libft.h"

void	ft_lstiter(t_list *lst, t_list (*f)(t_list *elem))
{
	while (lst->next)
	{
		f(lst);
		lst = lst->next;
	}
}
