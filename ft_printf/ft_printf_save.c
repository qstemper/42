/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_save.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 03:18:36 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/07 10:24:23 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		save_buff(void *buff, size_t size)
{
	t_list	*cp;

	if (!size)
		return ;
	cp = ft_lstnew(buff, size);
	if (!cp)
		return ;
	ft_lstaddback(buff_list(), cp);
}
