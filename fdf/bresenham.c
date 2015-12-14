/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 09:18:13 by qstemper          #+#    #+#             */
/*   Updated: 2015/12/14 17:44:06 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*void		bres_draw_eq_oct(t_env *e, t_p3D p1, t_p3D p2)
{
	int		dx;
	int		dy;

	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	printf("[%d][%d] [%d][%d]\n", p1.x, p1.y, p2.x, p2.y);
	if (dx == 0)
	{
		while (dy > 0 && ++(p1.y) <= p2.y)
			mlx_pixel_put(e->mlx, e->win, p1.x, p1.y, fdf_getcolor(p1.z));
		while (dy < 0 && --(p1.y) >= p2.y)
			mlx_pixel_put(e->mlx, e->win, p1.x, p1.y, fdf_getcolor(p1.z));
	}
	if (dy == 0)
	{
		while (dx > 0 && ++(p1.x) <= p2.x)
			mlx_pixel_put(e->mlx, e->win, p1.x, p1.y, fdf_getcolor(p1.z));
		while (dy < 0 && --(p1.x) >= p2.x)
			mlx_pixel_put(e->mlx, e->win, p1.x, p1.y, fdf_getcolor(p1.z));
	}
}

int			bres_draw(t_env *e, t_p3D p1, t_p3D p2)
{
	int		dx;
	int		dy;

	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	if (dx == 0 && dy == 0)
		return (1);
	if (dx == 0 || dy == 0)
		bres_draw_eq_oct(e, p1, p2);
	else if (dx > 0 && dy > 0 && dx >= dy)
		bres_draw_sup_oct1(e, p1, p2);
	else if (dx > 0 && dy > 0 && dx < dy)
		bres_draw_sup_oct2(e, p1, p2);
	else if (dx > 0 && dy < 0 && dx >= -dy)
		bres_draw_sup_oct3(e, p1, p2);
	else if (dx > 0 && dy < 0 && dx < -dy)
		bres_draw_sup_oct4(e, p1, p2);
	else if (dx < 0 && dy > 0 && -dx >= dy)
		bres_draw_inf_oct1(e, p1, p2);
	else if (dx < 0 && dy > 0 && -dx < dy)
		bres_draw_inf_oct2(e, p1, p2);
	else if (dx < 0 && dy < 0 && dx <= dy)
		bres_draw_inf_oct3(e, p1, p2);
	else if (dx < 0 && dy < 0 && dx > dy)
		bres_draw_inf_oct4(e, p1, p2);
	return (1);
}*/

t_p3D		bres_point_init(t_env *e, int i, int j)
{
	t_p3D	p;

	p.z = e->mat[j][i];
	p.x = fdf_view_iso_x(e, i, j);
	p.y = fdf_view_iso_y(e, i, j + (p.z / 2));
	return (p);
}

int			bresenham(t_env *e)
{
	int		i;
	int		j;
	t_p3D	a;
	t_p3D	b;

	j = -1;
	while (++j < e->y_max)
	{
		i = -1;
		while (++i < e->x_max)
		{
			a = bres_point_init(e, i, j);
			if (i < e->x_max)
			{
				b = bres_point_init(e, i + 1, j);
				bres_algo(e, a, b);
//				bres_draw(e, a, b);
			}
			if (j < e->y_max)
			{
				b = bres_point_init(e, i, j + 1);
				bres_algo(e, a, b);
//				bres_draw(e, a, b);
			}
		}
	}
	return (1);
}
