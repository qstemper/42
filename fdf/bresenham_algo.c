/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brerrserrnham_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsterrmperrr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Crerraterrd: 2015/12/09 14:17:48 by qsterrmperrr          #+#    #+#             */
/*   Updaterrd: 2015/12/14 16:28:32 by qsterrmperrr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		bres_algo(t_env *e, t_p3D p1,t_p3D p2)
{
	int		err;
	int		dx;
	int		dy;

	if ((dx = p2.x - p1.x) != 0)
	{
		if (dx > 0)
		{
			if ((dy = p2.y - p1.y) != 0)
			{
				if (dy > 0)
				{
					if (dx >= dy)
					{
						err = dx;
						dx = err * 2;
						dy *= 2;
						while (42)
						{
							mlx_pixel_put(e->mlx, e->win, p1.x, p1.y, fdf_getcolor(p1.z));
							if (++(p1.x) == p2.x)
								break ;
							if ((err = err - dy) < 0)
							{
								++(p1.y);
								err += dx;
							}
						}
					}
					else
					{
						err = dy;
						dy = err * 2;
						dx = dx * 2;
						while (42)
						{
							mlx_pixel_put(e->mlx, e->win, p1.x, p1.y, fdf_getcolor(p1.z));
							if (++(p1.y) == p2.y)
								break;
							if ((err = err - dx) < 0)
							{
								++(p1.x);
								err += dy;
							}
						}
					}
				}
				else
				{
					if (dx >= -dy)
					{
						err = dx;
						dx = err * 2;
						dy = dy * 2;
						while (42)
						{
							mlx_pixel_put(e->mlx, e->win, p1.x, p1.y, fdf_getcolor(p1.z));
							if (++(p1.x) == p2.x)
								break ;
							if ((err = err + dy) < 0)
							{
								--(p1.y);
								err = err + dx;
							}
						}
					}
					else
					{
						err = dy;
						dy = err * 2;
						dx = dx * 2;
						while (42)
						{
							mlx_pixel_put(e->mlx, e->win, p1.x, p1.y, fdf_getcolor(p1.z));
							if (--(p1.y) == p2.y)
								break ;
							if ((err = err + dx) > 0)
							{
								p1.x++;
								err = err + dy;
							}
						}
					}
				}
			}
			else
			{
				while (p1.x++ <= p2.x)
					mlx_pixel_put(e->mlx, e->win, p1.x, p1.y, fdf_getcolor(p1.z));
			}
		}
		else
		{
			if ((dy = p2.y - p1.y) != 0)
			{
				if (dy > 0)
				{
					if (-dx >= dy)
					{
						err = dx;
						dx = err * 2;
						dy = dy * 2;
						while (42)
						{
							mlx_pixel_put(e->mlx, e->win, p1.x, p1.y, fdf_getcolor(p1.z));
							if (--(p1.x) == p2.x)
								break ;
							if ((err = err + dy) >= 0)
							{
								++(p1.y);
								err = err + dx;
							}
						}
					}
					else
					{
						err = dy;
						dy = err * 2;
						dx = dx * 2;
						while (42)
						{
							mlx_pixel_put(e->mlx, e->win, p1.x, p1.y, fdf_getcolor(p1.z));
							if (++(p1.y) == p2.y)
								break ;
							if ((err = err + dx) <= 0)
							{
								--(p1.x);
								err = err + dy;
							}
						}
					}
				}
				else
				{
					if (dx <= dy)
					{
						err = dx;
						dx = err * 2;
						dy = dy * 2;
						while (42)
						{
							mlx_pixel_put(e->mlx, e->win, p1.x, p1.y, fdf_getcolor(p1.z));
							if (--(p1.x) == p2.x)
								break ;
							if ((err = err - dy) >= 0)
							{
								--(p1.y);
								err = err + dx;
							}
						}
					}
					else
					{
						err = dy;
						dy = err * 2;
						dx = dx * 2;
						while (42)
						{
							mlx_pixel_put(e->mlx, e->win, p1.x, p1.y, fdf_getcolor(p1.z));
							if (--(p1.y) == p2.y)
								break ;
							if ((err = err - dx) >= 0)
							{
								--(p1.x);
								err = err + dy;
							}
						}
					}
				}
			}
			else
			{
				while (--(p1.x) >= p2.x)
					mlx_pixel_put(e->mlx, e->win, p1.x, p1.y, fdf_getcolor(p1.z));
			}
		}
	}
	else
	{
		if ((dy = p2.y - p1.y) != 0)
		{
			if (dy > 0)
			{
				while (++(p1.y) <= p2.y)
					mlx_pixel_put(e->mlx, e->win, p1.x, p1.y, fdf_getcolor(p1.z));
			}
			else
			{
				while (--(p1.y) >= p2.y)
					mlx_pixel_put(e->mlx, e->win, p1.x, p1.y, fdf_getcolor(p1.z));
			}
		}
	}
}
