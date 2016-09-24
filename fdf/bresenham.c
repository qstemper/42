/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 15:53:45 by qstemper          #+#    #+#             */
/*   Updated: 2016/09/23 00:17:45 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		bres_draw_dx_sup(t_env *e, t_p3d a, t_p3d b, int color)
{
	if (e->dy > 0)
	{
		if (e->dx >= e->dy)
			bres_sup_oct1(e, a, b, color);
		else
			bres_sup_oct2(e, a, b, color);
	}
	else if (e->dy < 0)
	{
		if (e->dx >= -e->dy)
			bres_sup_oct3(e, a, b, color);
		else
			bres_sup_oct4(e, a, b, color);
	}
	else
	{
		while ((int)a.x <= (int)b.x)
		{
			mlx_pixel_put(e->mlx, e->win, a.x, a.y, color);
			a.x = (int)a.x + 1;
		}
	}
}

void		bres_draw_dx_inf(t_env *e, t_p3d a, t_p3d b, int color)
{
	if (e->dy > 0)
	{
		if (-e->dx >= e->dy)
			bres_inf_oct1(e, a, b, color);
		else
			bres_inf_oct2(e, a, b, color);
	}
	else if (e->dy < 0)
	{
		if (e->dx <= e->dy)
			bres_inf_oct3(e, a, b, color);
		else
			bres_inf_oct4(e, a, b, color);
	}
	else
	{
		while ((int)a.x >= (int)b.x)
		{
			mlx_pixel_put(e->mlx, e->win, (int)a.x, (int)a.y, color);
			a.x = (int)a.x - 1;
		}
	}
}

void		bres_draw(t_env *e, t_p3d a, t_p3d b)
{
	int		color;

	e->dx = (int)b.x - (int)a.x;
	e->dy = (int)b.y - (int)a.y;
	if (e->color == 0)
		color = e->color;
	else
		color = bres_color(fdf_getcolor(a.z), fdf_getcolor(b.z));
	if (e->dx > 0)
		bres_draw_dx_sup(e, a, b, color);
	else if (e->dx < 0)
		bres_draw_dx_inf(e, a, b, color);
	else
		bres_dx_null(e, a, b, color);
}

t_p3d		bres_point_init(t_env *e, int i, int j)
{
	t_p3d	p;

	p.z = e->mat[j][i];
	p.x = fdf_view_iso_x(e, i, j);
	p.y = fdf_view_iso_y(e, i, j);
	return (p);
}

void		bresenham(t_env *e)
{
	int		i;
	int		j;
	t_p3d	a;
	t_p3d	b;

	j = -1;
	while (++j <= e->y_max)
	{
		i = -1;
		while (++i <= e->x_max)
		{
			a = bres_point_init(e, i, j);
			if (a.z == INT_MIN)
				continue ;
			bresenham2(e, i, j, a, b);
		}
	}
}
