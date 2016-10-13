/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <qstemper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 10:13:57 by qstemper          #+#    #+#             */
/*   Updated: 2015/11/27 13:38:47 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstcpy(t_list *lst)
{
	t_list	*list;
	t_list	*elem;

	if (!lst)
		return (NULL);
	while (lst)
	{
		elem = ft_lstnew(lst->content, lst->content_size);
		ft_lstaddback(&list, elem);
		lst = lst->next;
	}
	return (list);
}
