/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bres_draw_dx_null.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 15:19:01 by qstemper          #+#    #+#             */
/*   Updated: 2015/12/16 15:30:14 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bres_dx_null(t_env *e, t_p3d a, t_p3d b, int color)
{
	if (e->dy > 0)
	{
		while (a.y <= b.y)
		{
			mlx_pixel_put(e->mlx, e->win, a.x, a.y, color);
			a.y = a.y - 1;
		}
	}
	else if (e->dy < 0)
	{
		while (a.y >= b.y)
		{
			mlx_pixel_put(e->mlx, e->win, a.x, a.y, color);
			a.y = a.y - 1;
		}
	}
}
