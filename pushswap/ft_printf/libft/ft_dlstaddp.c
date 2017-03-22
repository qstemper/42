/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstaddp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 09:04:22 by qstemper          #+#    #+#             */
/*   Updated: 2017/03/22 09:04:24 by qstemper         ###   ########.fr       */
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
