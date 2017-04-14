/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstaddn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 10:40:07 by qstemper          #+#    #+#             */
/*   Updated: 2017/04/14 10:40:09 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_dlstaddn(t_dlist **alst, t_dlist *elem)
{
	t_dlist		*cp;

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
