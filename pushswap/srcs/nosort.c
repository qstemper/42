/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nosort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 08:47:34 by qstemper          #+#    #+#             */
/*   Updated: 2017/03/22 08:47:39 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int		nosort(t_dlist *stack, int o, int finish)
{
	while (stack && stack->n)
	{
		if (*(int *)stack->content > *(int *)stack->n->content)
			return (1);
		stack = stack->n;
	}
	if (!finish)
		return (0);
	if (IS(O_DEBUG, o) || IS(O_STROKE, o))
	{
		if (IS(O_COLOR, o))
			ft_printf("{pink}Stroke{eoc}: 0\n");
		else
			ft_printf("Stroke: 0\n");
	}
	return (0);
}
