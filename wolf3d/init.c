/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 13:43:50 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/05 12:12:57 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	init_player(t_env *e)
{
	e->player.pos.x = 0;
	e->player.pos.y = 0;
	e->player.dir.x = -1;
	e->player.dir.y = 0;
	e->player.z = 0;
	e->player.plane.x = 0;
	e->player.plane.y = 0.66;
	e->player.turning_speed = 0.05;
	e->player.mv_speed = 0.05;
	e->player.mv_up = 0;
	e->player.mv_down = 0;
	e->player.mv_left = 0;
	e->player.mv_right = 0;
	e->player.mv_jump = 0;
	e->player.jumping = 0;
}

static void	init_mlx(t_env *e)
{
	if (!(e->mlx.mlx = mlx_init()))
	{
		ft_putendl("ERROR INITIALIZATION MLX");
		exit(1);
	}
	e->mlx.bpp = 0;
	e->mlx.size_line = 0;
	if (!(e->mlx.img = mlx_new_image(e->mlx.mlx, WIDTH, HEIGHT)))
	{
		ft_putendl("ERROR IMAGE CREATING");
		exit(1);
	}
	e->mlx.data = mlx_get_data_addr(e->mlx.img, &(e->mlx.bpp), \
			&(e->mlx.size_line), &(e->mlx.endian));
	e->mlx.last_frame = clock();
	e->mlx.next_frame = 0;
}

t_env		*init_env(void)
{
	t_env	*e;

	if (!(e = (t_env *)malloc(sizeof(t_env))))
		error_malloc();
	e->width = WIDTH;
	e->height = HEIGHT;
	init_player(e);
	init_mlx(e);
	e->col_north_wall = 0xff0000;
	e->col_south_wall = 0x00ff00;
	e->col_east_wall = 0x0000ff;
	e->col_west_wall = 0x884da7;
	e->col_sky = 0x26c4ec;
	e->col_ground = 0xcecece;
	return (e);
}
