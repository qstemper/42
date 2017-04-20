/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 10:40:41 by qstemper          #+#    #+#             */
/*   Updated: 2017/04/14 10:40:43 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist			*ft_dlstmap(t_dlist *lst, t_dlist *(*f)(t_dlist *elem))
{
	t_dlist		*new;
	t_dlist		*alst;

	new = NULL;
	alst = new;
	while (lst)
	{
		if (f)
			new = f(lst);
		else
			new = ft_dlstnew(lst->content, lst->content_size);
		if (!new)
		{
			ft_dlstdel(&alst, NULL);
			return (NULL);
		}
		ft_dlstaddn(&alst, new);
		lst = lst->n;
	}
	return (alst);
}
