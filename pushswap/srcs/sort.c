/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 08:49:11 by qstemper          #+#    #+#             */
/*   Updated: 2017/03/22 10:22:42 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static size_t	getmin(t_dlist *stack, int *min)
{
	size_t		i;
	size_t		pos;

	i = 0;
	*min = INT_MAX;
	while (stack)
	{
		if (*(int *)stack->content < *min)
		{
			*min = *(int *)stack->content;
			pos = i;
		}
		stack = stack->n;
		i++;
	}
	return (pos);
}

static int		handle_stack_a(t_dlist **astack, size_t size, int o)
{
	int			stroke;
	int			min;

	stroke = 0;
	if (getmin(*astack, &min) > (size / 2))
		stroke += reverse_roll(astack, min, o);
	else
		stroke += roll(astack, min, o);
	return (stroke);
}

static void		handle_stack_b(t_dlist **astack_a, t_dlist **astack_b, \
					int stroke, int o)
{
	while (*astack_b)
	{
		ft_printf("pa\n");
		op_px(astack_b, astack_a, &stroke);
	}
	if (IS(O_DEBUG, o) || IS(O_STROKE, o))
	{
		if (IS(O_COLOR, o))
			ft_printf("{pink}Stroke{eoc}: %d\n", stroke);
		else
			ft_printf("Stroke: %d\n", stroke);
	}
}

void			sort(t_dlist **astack_a, t_dlist **astack_b, \
					size_t size, int o)
{
	int			stroke;
	int			flag;

	stroke = 0;
	flag = 1;
	while (*astack_a)
	{
		if ((size < CHECKSORT) && !nosort(*astack_a, o, 0))
		{
			flag = 0;
			break ;
		}
		else if ((*astack_a)->n && !(*astack_a)->n->n)
			break ;
		stroke += handle_stack_a(astack_a, size, o);
		ft_printf("pb\n");
		op_px(astack_a, astack_b, &stroke);
		size--;
	}
	if (flag)
	{
		ft_printf("sa\n");
		op_sx(astack_a, &stroke);
	}
	handle_stack_b(astack_a, astack_b, stroke, o);
}
