/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 03:56:42 by qstemper          #+#    #+#             */
/*   Updated: 2016/09/27 03:56:49 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_dlist		*dlist_map(t_dlist *list, t_dlist *(*f)(t_dlist *elem))
{
	t_dlist	*new;
	t_dlist	*alst;

	new = NULL;
	alst = new;
	while (list)
	{
		if (f)
			new = f(list);
		else
			new = dlist_new(list->content, list->content_size);
		if (!new)
		{
			dlist_del(&alst, NULL);
			return (NULL);
		}
		dlist_add_n(&alst, new);
		list = list->n;
	}
	return (alst);
}
