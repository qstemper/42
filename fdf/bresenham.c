/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 16:03:51 by qstemper          #+#    #+#             */
/*   Updated: 2015/12/09 16:24:45 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			bres_equal_0(int x1, int x2, int y1, int y2, t_env *e)
{
	int		dx;
	int		dy;

	dx = x2 - x1;
	dy = y2 - y1;
	while (dx == 0 && y1 != y2)
	{
		mlx_pixel_put(e->mlx, e->win, x1, y1, getcolor(y1));
		if (dy-- > 0)
			y1++;
		else if (dy++ < 0)
			y1--;
	}
	while (dy == 0 && x1 != x2)
	{
		mlx_pixel_put(e->mlx, e->win, x1, y1, getcolor(x1));
		if (dx-- > 0)
			x1++;
		else if (dx++ < 0)
			x1--;
	}
}

void			bres_sup_0(int x1, int x2, int y1, int y2, t_env *e)
{
	int dx;
	int dy;

	dx = x2 - x1;
	dy = y2 - y1;

}

void			bresenham(int x1, int x2, int y1, int y2, t_env *e)
{
	int		dx;
	int		dy;

	dx = x2 - x1;
	dy = y2 - y1;
	if (dx == 0 || dy == 0)
		bres_equal_0(x1, x2, y1, y2, e);
	if (dx > 0 || dy > 0)
		bres_sup_0(x1, x2, y1, y2, e);
}
