/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <qstemper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 10:43:26 by qstemper          #+#    #+#             */
/*   Updated: 2015/12/18 19:05:33 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			fdf_getcolor(int c)
{
	if (!c)
		return (0xffffff);
	else if (c < 0)
		return (NEG_COLOR(c));
	else if (c > 0)
		return (POS_COLOR(c));
	return (UNKNOWN_COLOR(c));
}

int			draw(void *p)
{
	t_p3d	t;
	t_env	*e;
	int		i;
	int		j;

	e = (t_env *)p;
	j = 0;
	while (j <= e->y_max)
	{
		i = 0;
		while (i <= e->x_max)
		{
			t.z = (float)e->mat[j][i];
			t.x = fdf_view_iso_x(e, i, j);
			t.y = fdf_view_iso_y(e, i, j);
			mlx_pixel_put(e->mlx, e->win, (int)t.x, (int)t.y, fdf_getcolor((int)t.z));
			i++;
		}
		j++;
	}
	bresenham(e, 1);
	return (1);
}

int			clear(void *p)
{
	t_p3d	t;
	t_env	*e;
	int		i;
	int		j;

	e = (t_env *)p;
	j = 0;
	while (j <= e->y_max)
	{
		i = 0;
		while (i <= e->x_max)
		{
			t.z = (float)e->mat[j][i];
			t.x = fdf_view_iso_x(e, i, j);
			t.y = fdf_view_iso_y(e, i, j);
			mlx_pixel_put(e->mlx, e->win, t.x, t.y, 0);
			i++;
		}
		j++;
	}
	bresenham(e, 0);
	return (1);
}

int			key(int keycode, void *p)
{
	printf("key : [%d]\n", keycode);
	if (keycode == 69 || keycode == 78)
		zoom(keycode, p);
	if (keycode == 15)
		reinit(p);
	if (keycode == 126)
		modif_plus_z(p);
	if (keycode == 125)
		modif_minus_z(p);
	if (keycode == 53 || keycode == 12)
		destroy_window(p);
	return (1);
}

int			fdf_mlx(t_list **list, char *str, int x, int y)
{
	t_env	e;

	e.list = *list;
	e.x_max = x;
	e.y_max = y;
	e.zoom = 1.0;
	e.mat = matrix_fill(e);
	if (!(e.mlx = mlx_init()))
		return (0);
	if (!(e.win = mlx_new_window(e.mlx, 1024, 1024, str)))
		return (0);
	mlx_key_hook(e.win, key, (void *)&e);
	mlx_expose_hook(e.win, draw, (void *)&e);
	mlx_loop(e.mlx);
	return (1);
}
