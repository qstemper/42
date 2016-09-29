/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_add_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 03:19:05 by qstemper          #+#    #+#             */
/*   Updated: 2016/09/27 03:56:08 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		dlist_add_n(t_dlist **alst, t_dlist *elem)
{
	t_dlist	*cp;

	if (!*alst)
	{
		*alst = elem;
		return ;
	}
	cp = *alst;
	while (cp->n)
		cp = cp->n;
	cp->n = elem;
	elem->p = cp;
}
