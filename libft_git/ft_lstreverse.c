/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstreverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <qstemper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 10:51:56 by qstemper          #+#    #+#             */
/*   Updated: 2015/11/24 14:21:27 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstreverse(t_list *lst)
{
	t_list	*list;
	t_list	*tmp;
	t_list	*elem;
	size_t	i;
	size_t	j;

	list = NULL;
	if (lst == NULL)
		return (NULL);
	tmp = lst;
	i = ft_lstlen(lst);
	while (i > 0)
	{
		j = 1;
		while (j++ < i)
			lst = lst->next;
		elem = ft_lstnew(lst->content, lst->content_size);
		if (elem == NULL)
			return (NULL);
		ft_lstaddback(&list, elem);
		i--;
		lst = tmp;
	}
	return (list);
}
