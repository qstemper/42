/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mult_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 08:47:03 by qstemper          #+#    #+#             */
/*   Updated: 2017/03/22 10:18:17 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void		op_ss(t_dlist **astack_a, t_dlist **astack_b, int *stroke)
{
	op_sx(astack_a, stroke);
	op_sx(astack_b, stroke);
}

void		op_rs(t_dlist **astack_a, t_dlist **astack_b, int *stroke)
{
	op_rx(astack_a, stroke);
	op_rx(astack_b, stroke);
}

void		op_rrs(t_dlist **astack_a, t_dlist **astack_b, int *stroke)
{
	op_rrx(astack_a, stroke);
	op_rrx(astack_b, stroke);
}

void		op_px(t_dlist **astack_pop, t_dlist **astack_push, int *stroke)
{
	t_dlist	*tmp;

	if (!(*astack_pop))
		return ;
	tmp = *astack_pop;
	*astack_pop = (*astack_pop)->n;
	if (*astack_pop)
		(*astack_pop)->p = NULL;
	tmp->n = NULL;
	tmp->p = NULL;
	ft_dlstaddp(astack_push, tmp);
	(*stroke)++;
}
