/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 14:05:59 by qstemper          #+#    #+#             */
/*   Updated: 2016/09/29 10:41:06 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	key_mv(t_env *e, int keycode)
{
	if (keycode == MOVE_UP)
		e->player.mv_up = !e->player.mv_up;
	if (keycode == MOVE_DOWN)
		e->player.mv_down = !e->player.mv_down;
	if (keycode == MOVE_LEFT)
		e->player.mv_left = !e->player.mv_left;
	if (keycode == MOVE_RIGHT)
		e->player.mv_right = !e->player.mv_right;
	if (keycode == JUMP && e->player.mv_jump == 0)
		e->player.mv_jump = 1;
	if (keycode == ESC)
	{
		mlx_destroy_window(e->mlx.mlx, e->mlx.win);
		exit(0);
	}
	printf("%d\n", keycode);
}

int		key_press(t_env *e, int keycode)
{
	key_mv(e, keycode);
	return (0);
}

int		key_hook(t_env *e, int keycode)
{
	key_mv(e, keycode);
	return (0);
}
