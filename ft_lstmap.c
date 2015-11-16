#include "libft.h"

t_list *ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlst;
	t_list	*temp;
	t_list	*temp2;
	
	if (lst == NULL || f == NULL)
		return (NULL);
	temp2 = f(lst);
	if ((newlst = ft_lstnew(temp2->content, temp2->content_size)) != NULL)
	{
		tmp = newlst;
		lst = lst->next;
		while (lst->next)
		{
			temp2 = f(lst);
			if ((tmp->next = ft_lstnew(temp2->content, temp2->content_size)) == NULL)
				return (NULL);	
			tmp = tmp->next;
			lst = lst->next;
		}
		return (newlst);
	}
	return (NULL);
}
