/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 15:39:43 by qstemper          #+#    #+#             */
/*   Updated: 2016/09/27 01:21:06 by qstemper         ###   ########.fr       */
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
	int		j;

	e = (t_env *)p;
	mlx_destroy_window(e->mlx, e->win);
	ft_lstdel(&(e->list), NULL);
	j = 0;
	while (j <= e->y_max)
	{
		free(e->mat[j]);
		j++;
	}
	free(e->mat);
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
	j = -1;
	while (++j <= e->y_max)
	{
		i = -1;
		while (++i <= e->x_max)
		{
			if (e->mat[j][i] == INT_MIN)
				i++;
			if (e->mat[j][i] != 0)
				e->mat[j][i] = (e->mat[j][i] == -1) ? 1 : e->mat[j][i] + 1;
			t.x = fdf_view_iso_x(e, i, j);
			t.y = fdf_view_iso_y(e, i, j);
			mlx_pixel_put(e->mlx, e->win, t.x, t.y, fdf_getcolor((int)t.z));
		}
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
	j = -1;
	while (++j <= e->y_max)
	{
		i = -1;
		while (++i <= e->x_max)
		{
			if (e->mat[j][i] == INT_MIN)
				i++;
			if (e->mat[j][i] != 0)
				e->mat[j][i] = (e->mat[j][i] == 1) ? -1 : e->mat[j][i] - 1;
			t.x = fdf_view_iso_x(e, i, j);
			t.y = fdf_view_iso_y(e, i, j);
			mlx_pixel_put(e->mlx, e->win, t.x, t.y, fdf_getcolor((int)t.z));
		}
	}
	draw(e);
}
