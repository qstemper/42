/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <qstemper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 10:43:26 by qstemper          #+#    #+#             */
/*   Updated: 2015/12/08 13:51:48 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			key(int keycode, void *p)
{
	t_env	e;

	e = *((t_env *)p);
	if (keycode == 53 || keycode == 12)
	{
		mlx_destroy_window(e.mlx, e.win);
		ft_lstdel(&(e.list), NULL);
		exit(0);
	}
	return (1);
}

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
	t_p3D 	t;
	t_env	e;
	int		i;
	int		j;

	e = *((t_env *)p);
	j = 0;
	while (j <= e.y_max)
	{
		i = 0;
		while (i <= e.x_max)
		{
			t.x = i;
			t.y = j;
			t.z = e.mat[j][i];
			mlx_pixel_put(e.mlx, e.win, t.x * GAP, t.y * GAP, getcolor(t.z));
			i++;
		}
		j++;
	}
	return (1);
}

int			fdf_mlx(t_list **list, char *str, int x, int y)
{
	t_env	e;

	e.list = *list;
	e.x_max = x;
	e.y_max = y;
	e.mat = matrix_fill(e);
	printf("%s: [%d][%d]\n", str, x, y);
	if (!(e.mlx = mlx_init()))
		return (0);
	if (!(e.win = mlx_new_window(e.mlx, 1024, 1024, str)))
		return (0);
	mlx_key_hook(e.win, key, (void *)&e);
	mlx_expose_hook(e.win, draw, (void *)&e);
	mlx_loop(e.mlx);
	return (1);
}
