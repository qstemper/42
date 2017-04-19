/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <qstemper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/17 14:18:57 by qstemper          #+#    #+#             */
/*   Updated: 2015/11/26 12:22:43 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlst;
	t_list	*elem;

	if (lst == NULL || f == NULL)
		return (NULL);
	newlst = NULL;
	while (lst)
	{
		elem = f(lst);
		if (elem == NULL)
			return (NULL);
		ft_lstaddback(&newlst, elem);
		lst = lst->next;
	}
	return (newlst);
}
