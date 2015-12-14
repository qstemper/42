/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bres_draw_inf_oct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 15:21:29 by qstemper          #+#    #+#             */
/*   Updated: 2015/12/14 16:56:45 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		bres_draw_inf_oct1(t_env *e, t_p3D p1, t_p3D p2)
{
	int		err;
	int		dx;
	int		dy;

	printf("Inf oct1 : [%d][%d] [%d][%d]\n", p1.x, p1.y, p2.x, p2.y);
	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	err = dx;
	dx = err * 2;
	dy *= 2;
	while (42)
	{
		mlx_pixel_put(e->mlx, e->win, p1.x, p1.y, fdf_getcolor(p1.z));
		if (--(p1.x) == p2.x)
			break;
		if ((err += dy) >= 0)
		{
			++(p1.y);
			err += dx;
		}
	}
}

void		bres_draw_inf_oct2(t_env *e, t_p3D p1, t_p3D p2)
{
	int		err;
	int		dx;
	int		dy;

	printf("Inf oct2 : [%d][%d] [%d][%d]\n", p1.x, p1.y, p2.x, p2.y);
	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	err = dy;
	dy = err * 2;
	dx *= 2;
	while (42)
	{
		mlx_pixel_put(e->mlx, e->win, p1.x, p1.y, fdf_getcolor(p1.z));
		if (++(p1.y) == p2.y)
			break;
		if ((err += dx) <= 0)
		{
			--(p1.x);
			err += dy;
		}
	}
}

void		bres_draw_inf_oct3(t_env *e, t_p3D p1, t_p3D p2)
{
	int		err;
	int		dx;
	int		dy;

	printf("Inf oct3 : [%d][%d] [%d][%d]\n", p1.x, p1.y, p2.x, p2.y);
	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	err = dx;
	dx = err * 2;
	dy *= 2;
	while (42)
	{
		mlx_pixel_put(e->mlx, e->win, p1.x, p1.y, fdf_getcolor(p1.z));
		if (--(p1.x) == p2.x)
			break;
		if ((err -= dy) >= 0)
		{
			--(p1.y);
			err += dx;
		}
	}
}

void		bres_draw_inf_oct4(t_env *e, t_p3D p1, t_p3D p2)
{
	int		err;
	int		dx;
	int		dy;

	printf("Inf oct4 : [%d][%d] [%d][%d]\n", p1.x, p1.y, p2.x, p2.y);
	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	err = dy;
	dy = err * 2;
	dx *= 2;
	while (42)
	{
		mlx_pixel_put(e->mlx, e->win, p1.x, p1.y, fdf_getcolor(p1.z));
		if (--(p1.y) == p2.y)
			break;
		if ((err -= dx) >= 0)
		{
			--(p1.x);
			err += dy;
		}
	}
}
