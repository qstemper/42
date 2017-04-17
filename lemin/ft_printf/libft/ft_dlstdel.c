/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 09:05:25 by qstemper          #+#    #+#             */
/*   Updated: 2017/03/22 09:05:27 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_dlstdel(t_dlist **alst, void (*del)(void *, size_t))
{
	t_dlist		*cp;

	while (*alst)
	{
		cp = (*alst)->n;
		ft_dlstdelone(alst, del);
		*alst = cp;
	}
}
