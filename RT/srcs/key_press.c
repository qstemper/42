/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 04:35:49 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/16 14:09:36 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		key_quit(t_env *e)
{
	mlx_destroy_window(e->mlx.mlx, e->mlx.win);
	mlx_destroy_image(e->mlx.mlx, e->mlx.img);
	free(*e);
	free(e);
	exit(0);
}

static int		key_arrow(int keycode, t_env *e)
{
	if (keycode == R_ARROW)
		e->event.key.right = 1;
	else if (keycode == L_ARROW)
		e->event.key.left = 1;
	else if (keycode == U_ARROW)
		e->event.key.up = 1;
	else if (keycode == D_ARROW)
		e->event.key.down = 1;
	return (keycode);
}

static int		key_wasd(int keycode, t_env *e)
{
	if (keycode == W)
		e->event.key.w = 1;
	else if (keycode == A)
		e->event.key.a = 1;
	else if (keycode == S)
		e->event.key.s = 1;
	else if (keycode == D)
		e->event.key.d = 1;
	return (keycode);
}

static int		key_num(int keycod, t_env *e)
{
	if (keycode == NUM_PLUS)
		e->event.key.num_plus = 1;
	else if (keycode == NUM_MINUS)
		e->event.key.num_minus = 1;
	else if (keycode == NUM_MULT)
	{
		e->e_scene.scene.diaph *= 1.05;
		e->frame.light_refresh = clock();
	}
	else if (keycode == NUM_DIV)
	{
		e->e_scene.scene.diaph /= 1.05;
		e->frame.light_refresh = clock();
	}
	return (keycode);
}

int				key_press(int keycode, t_env *e)
{
	if (keycode == ESC)
		key_quit(e);
	else if (keycode > 122 && keycode < 127)
		key_arrow(keycode, e);
	else if (keycode == PAGE_UP)
		e->event.key.page_up = 1;
	else if (keycode == PAGE_DOWN)
		e->event.key.page_down = 1;
	else if (keycode > 66 && keycode < 79)
		key_num(keycode, e);
	else if (keycode > -1 && keycode < 14)
		key_wasd(keycode, e);
	else if (keycode == DEL)
		e->event.key.del = 1;
	else if (keycode == CTRL_L || keycode == CTRL_R)
		e->event.key.ctrl = 1;
	else if (keycode == TAB)
		e->event.key.tab i= 1;
	else if (keycode == ALT_L || keycode == ALT_R)
		e->event.key.alt = 1;
	else if (keycode == CMD_L || keycode == CMD_R)
	{
		if (e->event.select_obj)
			duplicate_obj(e->event.select_obj);
	}
	return (keycode);
}
