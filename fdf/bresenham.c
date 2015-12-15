/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 15:53:45 by qstemper          #+#    #+#             */
/*   Updated: 2015/12/15 17:06:30 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		bres_draw(t_env *e, t_p3D a, t_p3D b, int c)
{
	int		err;
	int		dx;
	int		dy;
	int		color;

	printf("a.x[%d] a.y[%d] b.x[%d] b.y[%d]\n", a.x, a.y, b.x, b.y);
	if (c == 0)
		color = c;
	else
		color = fdf_getcolor(a.z);
	if ((dx = b.x - a.x) != 0)
	{
		if (dx > 0)
		{
			if ((dy = b.y - a.y) != 0)
			{
				if (dy > 0)
				{
					if (dx >= dy)
					{
						err = dx;
						dx = err * 2;
						dy = dy * 2;
						while (42)
						{
							mlx_pixel_put(e->mlx, e->win, a.x, a.y, color);
							if (++a.x == b.x)
								break ;
							if ((err = err - dy) < 0)
							{
								a.y = a.y + 1;
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
							mlx_pixel_put(e->mlx, e->win, a.x, a.y, color);
							if ((a.y = a.y + 1) == b.y)
								break ;
							if ((err = err - dx) < 0)
							{
								a.x = a.x + 1;
								err = err + dy;
							}
						}
					}
				}
				else if (dy < 0)
				{
					if (dx >= -dy)
					{
						err = dx;
						dx = err * 2;
						dy = dy * 2;
						while (42)
						{
							mlx_pixel_put(e->mlx, e->win, a.x, a.y, color);
							if ((a.x = a.x + 1) == b.x)
								break ;
							if ((err = err + dy) < 0)
							{
								a.y = a.y - 1;
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
							mlx_pixel_put(e->mlx, e->win, a.x, a.y, color);
							if ((a.y = a.y - 1) == b.y)
								break ;
							if ((err = err + dx) > 0)
							{
								a.x = a.x + 1;
								err = err + dy;
							}
						}
					}
				}
			}
			else
			{
				while (a.x <= b.x)
				{
					mlx_pixel_put(e->mlx, e->win, a.x, a.y, color);
					++(a.x);
				}
			}
		}
		else
		{
			if ((dy = b.y - a.y) != 0)
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
							mlx_pixel_put(e->mlx, e->win, a.x, a.y, color);
							if ((a.x = a.x - 1) == b.x)
								break ;
							if ((err = err + dy) >= 0)
							{
								a.y = a.y + 1;
								err = err + dy;
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
							mlx_pixel_put(e->mlx, e->win, a.x, a.y, color);
							if ((a.y = a.y + 1) == b.y)
								break ;
							if ((err = err + dx) <= 0)
							{
								a.x = a.x - 1;
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
							mlx_pixel_put(e->mlx, e->win, a.x, a.y, color);
							if ((a.x = a.x - 1) == b.x)
								break ;
							if ((err = err - dy) >= 0)
							{
								a.y = a.y - 1;
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
							mlx_pixel_put(e->mlx, e->win, a.x, a.y, color);
							if ((a.y = a.y - 1) == b.y)
								break ;
							if ((err = err - dx) >= 0)
							{
								a.x = a.x - 1;
								err = err + dy;
							}
						}
					}
				}
			}
			else
			{
				while (a.x >= b.x)
				{
					mlx_pixel_put(e->mlx, e->win, a.x, a.y, color);
					a.x = a.x - 1;
				}
			}
		}
	}
	else
	{
		if ((dy = b.y - a.y) != 0)
		{
			if (dy > 0)
			{
				while (a.y <= b.y)
				{
					mlx_pixel_put(e->mlx, e->win, a.x, a.y, color);
					a.y = a.y + 1;
				}
			}
			else if (dy < 0)
			{
				while (a.y >= b.y)
				{	
					mlx_pixel_put(e->mlx, e->win, a.x, a.y, color);
					a.y = a.y - 1;
				}
			}
		}
	}
	return (1);
}

t_p3D		bres_point_init(t_env *e, int i, int j)
{
	t_p3D	p;

	p.z = e->mat[j][i];
	printf("[%d][%d]\n", i, j);
	p.x = fdf_view_iso_x(e, i, j);
	p.y = fdf_view_iso_y(e, i, j + (p.z / 2));
	return (p);
}

int			bresenham(t_env *e, int c)
{
	int		i;
	int		j;
	t_p3D	a;
	t_p3D	b;

	j = 0;
	while (j <= e->y_max)
	{
		i = 0;
		while (i <= e->x_max)
		{
			a = bres_point_init(e, i, j);
			if (i < e->x_max)
			{
				b = bres_point_init(e, i + 1, j);
				bres_draw(e, a, b, c);
			}
			if (j < e->y_max)
			{
				b = bres_point_init(e, i, j + 1);
				bres_draw(e, a, b, c);
			}
			i++;
		}
		j++;
	}
	return (1);
}
