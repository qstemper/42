/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <qstemper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 10:43:26 by qstemper          #+#    #+#             */
/*   Updated: 2015/12/03 17:54:54 by qstemper         ###   ########.fr       */
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
	t_p3D 	tmp;
	t_env	e;
	t_list	*lst;

	e = *((t_env *)p);
	lst = e.list;
	while (lst)
	{
		tmp = *((t_p3D *)lst->content);
		mlx_pixel_put(e.mlx, e.win, tmp.x * GAP, tmp.y * GAP, getcolor(tmp.z));
		lst = lst->next;
	}
	return (1);
}

int			fdf_mlx(t_list **list, char *str, int x, int y)
{
	t_env	e;

	e.list = *list;
	e.x_max = x;
	e.y_max = y;
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
