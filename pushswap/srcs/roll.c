/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   roll.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 08:48:20 by qstemper          #+#    #+#             */
/*   Updated: 2017/03/22 10:16:29 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int			reverse_roll(t_dlist **astack, int min, int o)
{
	int		stroke;

	stroke = 0;
	while (*(int *)(*astack)->content != min)
	{
		ft_printf("rra\n");
		op_rrx(astack, &stroke);
	}
	(void)o;
	return (stroke);
}

int			roll(t_dlist **astack, int min, int o)
{
	int		stroke;

	stroke = 0;
	while (*(int *)(*astack)->content != min)
	{
		ft_printf("ra\n");
		op_rx(astack, &stroke);
	}
	(void)o;
	return (stroke);
}
