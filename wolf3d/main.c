/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 08:25:39 by qstemper          #+#    #+#             */
/*   Updated: 2016/09/28 09:06:07 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int			readsize(t_env *e, int fd)
{
	int				*size;
	char			*line;

	if (get_next_line(fd, &line) < 1)
		return (-1);
	size = ft_strsplittoint(line, ' ');
	e->map.sizex = size[0];
	e->map.sizey = size[1];
	return (0);
}

static int			readmap(t_env *e, int fd)
{
	char			*line;
	int				**worldmap;
	int				i;

	i = 0;
	if (!(worldmap = (int **)malloc(sizeof(int *) * e->map.sizex)))
		return (-1);
	while (get_next_line(fd, &line) > 0)
	{
		worldmap[i] = ft_strsplittoint(line, ' ');
		i++;
	}
	e->map.map = worldmap;
	return (0);
}

static int			readfile(t_env *e, char **av)
{
	int				fd;
	int				ret;

	if ((fd = open(*av, O_RDONLY)) == -1)
		return (-1);
	if ((ret = readsize(e, fd)) == -1)
		return (-1);
	if ((ret = readmap(e, fd)) == -1)
		return (-1);
	close(fd);
	return (0);
}

void				get_timeframe(t_env *e)
{
	struct timeval	time;

	e->prevtime = e->time;
	gettimeofday(&time, NULL);
	e->time = time.tv_sec * 1000 + time.tv_sec / 1000;
	e->frametime = e->time - e->prevtime;
	e->player.mspeed = e->frametime * 0.003;
	e->player.rspeed = e->frametime * 0.005;
}

int					main(int ac, char **av)
{
	t_env			e;
	int				ret;

	if (ac != 2)
		return (-1);
	if (!(e.mlx = mlx_init()))
		ft_putendl("ERROR MIX INITIALIZATION");
	if (!(e.win = mlx_new_window(e.mlx, WIDTH, HEIGHT, "WOLF 3D")))
		ft_putendl("ERROR CREATING WINDOW");
	e.img = NULL;
	e.player.pos.x = 5.0;
	e.player.pos.y = 5.0;
	e.player.dir.x = -1.0;
	e.player.dir.y = 0.0;
	e.ray.plane.x = 0.0;
	e.ray.plane.y = 0.80;
	e.time = 0.0;
	e.prevtime = 0.0;
	if ((ret = readfile(&e, av)) == -1)
		return (-1);
	mlx_loop_hook(e.mlx, &loop_hook, &e);
	mlx_hook(e.win, 2, (1L << 0), &key_press, &e);
	mlx_hook(e.win, 3, (1L << 1), key_press, &e);
	mlx_loop(e.mlx);
	return (0);
}
