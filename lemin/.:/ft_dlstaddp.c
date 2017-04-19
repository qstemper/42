/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstaddp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 10:40:15 by qstemper          #+#    #+#             */
/*   Updated: 2017/04/14 10:40:16 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_dlstaddp(t_dlist **alst, t_dlist *elem)
{
	t_dlist		*cp;

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
