/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bres_dx_sup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 12:55:37 by qstemper          #+#    #+#             */
/*   Updated: 2015/12/17 18:49:02 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		bres_sup_oct1(t_env *e, t_p3d a, t_p3d b, int color)
{
	int		err;

	err = e->dx;
	e->dx = err * 2;
	e->dy = e->dy * 2;
	while (42)
	{
		mlx_pixel_put(e->mlx, e->win, (int)a.x, (int)a.y, color);
		if ((int)(a.x = (int)a.x + 1) == (int)b.x)
			break ;
		if ((err = err - e->dy) < 0)
		{
			a.y = (int)a.y + 1;
			err = err + e->dx;
		}
	}
}

void		bres_sup_oct2(t_env *e, t_p3d a, t_p3d b, int color)
{
	int		err;

	err = e->dy;
	e->dy = err * 2;
	e->dx = e->dx * 2;
	while (42)
	{
		mlx_pixel_put(e->mlx, e->win, (int)a.x, (int)a.y, color);
		if ((int)(a.y = (int)a.y + 1) == (int)b.y)
			break ;
		if ((err = err - e->dx) < 0)
		{
			a.x = (int)a.x + 1;
			err = err + e->dy;
		}
	}
}

void		bres_sup_oct3(t_env *e, t_p3d a, t_p3d b, int color)
{
	int		err;

	err = e->dx;
	e->dx = err * 2;
	e->dy = e->dy * 2;
	while (42)
	{
		mlx_pixel_put(e->mlx, e->win, (int)a.x, (int)a.y, color);
		if ((int)(a.x = (int)a.x + 1) == (int)b.x)
			break ;
		if ((err = err + e->dy) < 0)
		{
			a.y = (int)a.y - 1;
			err = err + e->dx;
		}
	}
}

void		bres_sup_oct4(t_env *e, t_p3d a, t_p3d b, int color)
{
	int		err;

	err = e->dy;
	e->dy = err * 2;
	e->dx = e->dx * 2;
	while (42)
	{
		mlx_pixel_put(e->mlx, e->win, (int)a.x, (int)a.y, color);
		if ((int)(a.y = (int)a.y - 1) == (int)b.y)
			break ;
		if ((err = err + e->dx) > 0)
		{
			a.x = (int)a.x + 1;
			err = err + e->dy;
		}
	}
}
