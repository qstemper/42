/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump_darray2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 03:54:34 by qstemper          #+#    #+#             */
/*   Updated: 2016/09/27 03:57:18 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		dump_darray2(t_darray2 *darray, void (f)(void *))
{
	t_uint	i;

	i = 0;
	while (i < darray->size)
	{
		if (f)
			f(darray->array[i]);
		i++;
	}
}
