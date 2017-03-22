/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 13:48:46 by qstemper          #+#    #+#             */
/*   Updated: 2017/03/22 16:59:10 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void		rev_rot_a(t_stack *a, t_stack *b)
{
	int		tmp;
	int		i;

	tmp = a->tab[a->size - 1];
	i = a->size;
	while (i > 0)
	{
		a->tab[i] = a->tab[i - 1];
		i--;
	}
	a->tab[i] = tmp;
}

void		rev_rot_b(t_stack *a, t_stack *b)
{
	int		tmp;
	int		i;

	tmp = b->tab[b->size - 1];
	i = b->size;
	while (i > 0)
	{
		b->tab[i] = b->tab[i - 1];
		i--;
	}
	b->tab[i] = tmp;
}

void		rev_rot_both(t_stack *a, t_stack *b)
{
	rev_rot_a(a, b);
	rev_rot_b(a, b);
}
