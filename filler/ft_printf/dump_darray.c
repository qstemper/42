/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump_darray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 03:54:42 by qstemper          #+#    #+#             */
/*   Updated: 2016/09/27 03:57:12 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		dump_darray(t_darray *array)
{
	size_t	i;

	i = 0;
	ft_printf("\nDUMP AR :\n");
	ft_printf("data : %p\n", array->data);
	ft_printf("curr : %p\n", array->curr);
	ft_printf("end : %p\n", array->end);
	ft_printf("address : %p\n", array->address);
	ft_printf("size : %zu\n", array->size);
	ft_printf("i : %u\n\n", array->i);
	while (i < array->i)
	{
		ft_printf("\t");
		dump_i_darray(array, i);
		i++;
	}
	ft_printf("\nEND DUMP\n");
}
