/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_del.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 03:56:17 by qstemper          #+#    #+#             */
/*   Updated: 2016/09/27 03:56:22 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	dlist_del(t_dlist **alst, void (*del)(void *, size_t))
{
	t_dlist	*cp;

	while (*alst)
	{
		cp = (*alst)->n;
		dlist_delone(alst, del);
		*alst = cp;
	}
}
