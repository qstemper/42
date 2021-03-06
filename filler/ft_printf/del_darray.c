/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_darray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 03:20:14 by qstemper          #+#    #+#             */
/*   Updated: 2017/04/06 11:32:02 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	del_darray(t_darray *array)
{
	free(array->data);
	free(array->address);
	ft_bzero((void *)array, sizeof(t_darray));
}
