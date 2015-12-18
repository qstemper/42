/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 15:39:43 by qstemper          #+#    #+#             */
/*   Updated: 2015/12/18 19:05:32 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		zoom(int keycode, void *p)
{
	t_env	*e;

	e = (t_env *)p;
	clear(e);
	if (keycode == 69)
		e->zoom *= 2;
	else if (keycode == 78)
		e->zoom /= 2;
	draw(e);
}

void		destroy_window(void *p)
{
	t_env	*e;

	e = (t_env *)p;
	mlx_destroy_window(e->mlx, e->win);
	ft_lstdel(&(e->list), NULL);
	exit(0);
}

void		reinit(void *p)
{
	t_env	*e;

	e = (t_env *)p;
	clear(e);
	e->zoom = 1.0;
	draw(e);
}

void		modif_plus_z(void *p)
{
	t_env	*e;
	t_p3d	t;
	int		i;
	int		j;

	e = (t_env *)p;
	clear(e);
	j = 0;
	while (j <= e->y_max)
	{
		i = 0;
		while (i <= e->x_max)
		{
			if (e->mat[j][i] != 0)
			{
				if (e->mat[j][i] == -1)
					e->mat[j][i] = 1;
				else
					e->mat[j][i] += 1;
			}
			t.x = fdf_view_iso_x(e, i, j);
			t.y = fdf_view_iso_y(e, i, j);
			mlx_pixel_put(e->mlx, e->win, t.x, t.y, fdf_getcolor((int)t.z));
			i++;
		}
		j++;
	}
	draw(e);
}

void		modif_minus_z(void *p)
{
	t_env	*e;
	t_p3d	t;
	int		i;
	int		j;

	e = (t_env *)p;
	clear(e);
	j = 0;
	while (j <= e->y_max)
	{
		i = 0;
		while (i <= e->x_max)
		{
			if (e->mat[j][i] != 0)
			{
				if (e->mat[j][i] == 1)
					e->mat[j][i] = -1;
				else
					e->mat[j][i] -= 1;
			}
			t.x = fdf_view_iso_x(e, i, j);
			t.y = fdf_view_iso_y(e, i, j);
			mlx_pixel_put(e->mlx, e->win, t.x, t.y, fdf_getcolor((int)t.z));
			i++;
		}
		j++;
	}
	draw(e);
}
