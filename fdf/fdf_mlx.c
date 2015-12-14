/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <qstemper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 10:43:26 by qstemper          #+#    #+#             */
/*   Updated: 2015/12/09 14:45:47 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


static int	getcolor(int c)
{
	if (!c)
		return (0x0000ff);
	else if (c < 11)
		return (0x00ff00);
	else if (c > 10 && c < 49)
		return (0xff0000);
	return (0xf0f0f0);
}

int			draw(void *p)
{
	t_p3D	t;
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
			t.z = e->mat[j][i];
			t.x = fdf_view_iso_x(e, i, j);
			t.y = fdf_view_iso_y(e, i, j + (t.z / 2));
			mlx_pixel_put(e->mlx, e->win, t.x, t.y, getcolor(t.z));
			i++;
		}
		j++;
	}
	return (1);
}

int			clear(void *p)
{
	t_p3D	t;
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
			t.z = e->mat[j][i];
			t.x = fdf_view_iso_x(e, i, j);
			t.y = fdf_view_iso_y(e, i, j + (t.z / 2));
			mlx_pixel_put(e->mlx, e->win, t.x, t.y, 0);
			i++;
		}
		j++;
	}
	return (1);
}

int			key(int keycode, void *p)
{
	t_env	*e;

	e = (t_env *)p;
	printf("key : [%d]\n", keycode);
	if (keycode == 69)
	{
		clear(p);
		e->zoom *= 2;
		draw(p);
	if (keycode == 78)
	{
		clear(p);
		e->zoom /= 2;
		draw(p);
	}
	if (keycode == 53 || keycode == 12)
	{
		mlx_destroy_window(e->mlx, e->win);
		ft_lstdel(&(e->list), NULL);
		exit(0);
	}
	return (1);
}

int			mouse(int button, int x, int y, void *p)
{
	t_env		*e;

	e = (t_env *)p;
	printf("mouse : [%d] [%d]-[%d]\n", button, x, y);
	return (0);
}

int			fdf_mlx(t_list **list, char *str, int x, int y)
{
	t_env	e;

	e.list = *list;
	e.x_max = x;
	e.y_max = y;
	e.zoom = 1.0;
	e.mat = matrix_fill(e);
	printf("%s: [%d][%d]\n", str, x, y);
	if (!(e.mlx = mlx_init()))
		return (0);
	if (!(e.win = mlx_new_window(e.mlx, 1024, 1024, str)))
		return (0);
	mlx_key_hook(e.win, key, (void *)&e);
	mlx_expose_hook(e.win, draw, (void *)&e);
	mlx_mouse_hook(e.win, mouse, (void *)&e);
	mlx_loop(e.mlx);
	return (1);
}
