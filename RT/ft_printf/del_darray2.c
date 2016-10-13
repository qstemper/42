/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_darray2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 03:20:20 by qstemper          #+#    #+#             */
/*   Updated: 2016/09/27 03:55:27 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			del_darray2(t_darray2 *darray)
{
	t_uint	i;

	i = 0;
	while (i < darray->size)
	{
		if (darray->del)
			darray->del(darray->array[i]);
		free(darray->array[i]);
		i++;
	}
	free(darray->array);
	ft_bzero(darray, sizeof(t_darray2));
	return (1);
}
