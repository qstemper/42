/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_static.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 03:11:46 by qstemper          #+#    #+#             */
/*   Updated: 2016/09/27 04:01:28 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_list						**buff_list(void)
{
	static t_list			*buff;

	return (&buff);
}

t_printf_color				*col_attr(int i)
{
	static t_printf_color	color[NB_COLOR_ATTRIBUTE];
	static int				call;

	if (!call)
	{
		init_color(color);
		call = 1;
	}
	return (color + i);
}
