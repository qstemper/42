/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_darray2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 02:48:36 by qstemper          #+#    #+#             */
/*   Updated: 2016/09/27 02:48:43 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		new_darray2(t_darray2 *darray, size_t size, t_darray_del del)
{
	ft_bzero((void *)darray, sizeof(t_darray2));
	darray->array = (void **)ft_memalloc(sizeof(void *) * DARRAY2_OFFSET);
	if (!darray->array)
		return (1);
	darray->size_content = size;
	darray->size_max = DARRAY2_OFFSET;
	if (del)
		darray->del = del;
	return (0);
}
