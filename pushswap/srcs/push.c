/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 12:05:14 by qstemper          #+#    #+#             */
/*   Updated: 2017/03/22 16:58:57 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void		push_a(t_stack *a, t_stack *b)
{
	int		tmp;

	if (b->size == 0)
		return ;
	tmp = b->tab[0];
	b->size--;
	ft_memmove(b->tab, b->tab + 1, b->size * sizeof(int));
	ft_memmove(a->tab + 1, a->tab, a->size * sizeof(int));
	a->size++;
	a->tab[0] = tmp;
}

void		push_b(t_stack *a, t_stack *b)
{
	int		tmp;

	if (a->size == 0)
		return ;
	tmp = a->tab[0];
	a->size--;
	ft_memmove(a->tab, a->tab + 1, a->size * sizeof(int));
	ft_memmove(b->tab + 1, b->tab, b->size * sizeof(int));
	b->size++;
	b->tab[0] = tmp;
}
