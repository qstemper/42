/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 00:47:38 by qstemper          #+#    #+#             */
/*   Updated: 2016/09/27 00:49:46 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		bresenham2(t_env *e, int i, int j, t_p3d a)
{
	t_p3d	b;

	if (i < e->x_max)
	{
		b = bres_point_init(e, i + 1, j);
		if (b.z != INT_MIN)
			bres_draw(e, a, b);
	}
	if (j < e->y_max)
	{
		b = bres_point_init(e, i, j + 1);
		if (b.z != INT_MIN)
			bres_draw(e, a, b);
	}
}
