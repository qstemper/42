/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_add_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 03:19:00 by qstemper          #+#    #+#             */
/*   Updated: 2016/09/27 03:56:02 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		dlist_add_p(t_dlist **alst, t_dlist *elem)
{
	t_dlist	*cp;

	if (!*alst)
	{
		*alst = elem;
		return ;
	}
	cp = *alst;
	elem->n = cp;
	cp->p = elem;
	*alst = elem;
}
