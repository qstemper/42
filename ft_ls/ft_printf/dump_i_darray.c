/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump_i_darray.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 03:57:32 by qstemper          #+#    #+#             */
/*   Updated: 2016/09/27 03:57:39 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		dump_i_darray(t_darray *array, t_uint i)
{
	size_t	j;

	j = 0;
	ft_printf("address : %p\t |", array->address[i].data);
	while (j < array->address[i].size)
	{
		ft_printf("%d |", *((t_uchar *)(array->address[i].data + j)));
		j++;
	}
	ft_printf("\n");
}
