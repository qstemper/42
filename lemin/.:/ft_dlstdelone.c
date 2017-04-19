/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 10:40:23 by qstemper          #+#    #+#             */
/*   Updated: 2017/04/14 10:40:24 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstdelone(t_dlist **alst, void (*del)(void *, size_t))
{
	if (!*alst)
		return ;
	if (del)
		del((*alst)->content, (*alst)->content_size);
	ft_memdel((void **)alst);
}
