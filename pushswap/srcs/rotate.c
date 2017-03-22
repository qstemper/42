/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 13:41:27 by qstemper          #+#    #+#             */
/*   Updated: 2017/03/22 15:44:25 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void		rotate_a(t_stack *a, t_stack *b)
{
	int		tmp;
	int		i;

	tmp = a->tab[0];
	i = 0;
	while (i < a->size - 1)
	{
		a->tab[i] = a->tab[i + 1];
		i++;
	}
	a->tab[i] = tmp;
}

void		rotate_b(t_stack *a, t_stack *b)
{
	int		tmp;
	int		i;

	tmp = b->tab[0];
	i = 0;
	while (i < b->size - 1)
	{
		b->tab[i] = b->tab[i + 1];
		i++;
	}
	b->tab[i] = tmp;
}

void		rotate_both(t_stack *a, t_stack *b)
{
	rotate_a(a, b);
	rotate_b(a, b);
}
