/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_add_in.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 03:19:33 by qstemper          #+#    #+#             */
/*   Updated: 2016/09/27 03:55:42 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		dlist_add_in(t_dlist **alst, t_dlist *elem, t_uint i)
{
	t_dlist	*cp;
	t_dlist	*tmp;

	cp = *alst;
	while (i-- && cp)
		cp = cp->n;
	if (!cp)
		*alst = elem;
	else
	{
		tmp = cp->n;
		cp->n = elem;
		elem->p = cp;
		elem->n = tmp;
		if (tmp)
			tmp->p = elem;
	}
}
