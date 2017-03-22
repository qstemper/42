/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 11:52:43 by qstemper          #+#    #+#             */
/*   Updated: 2017/03/22 17:30:29 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void		swap_a(t_stack *a, t_stack *b)
{
	int		tmp;

	if (a->size == 0 || a->size == 1)
		return ;
	tmp = a->tab[0];
	a->tab[0] = a->tab[1];
	a->tab[1] = tmp;
}

void		swap_b(t_stack *a, t_stack *b)
{
	int		tmp;

	if (b->size == 0 || b->size == 1)
		return ;
	tmp = b->tab[0];
	b->tab[0] = b->tab[1];
	b->tab[1] = tmp;
}

void		swap_both(t_stack *a, t_stack *b)
{
	swap_a(a, b);
	swap_b(a, b);
}
