/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 07:45:31 by qstemper          #+#    #+#             */
/*   Updated: 2016/09/28 07:45:57 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frac.h"

static void	key_scale(int keycode, t_env *e)
{
	float	zoom;

	if (keycode == PAD_PLUS)
	{
		e->ptr->zoom_ratio *= 1.1;
		zoom = e->ptr->zoom_ratio;
		e->ptr->x1 += ((e->height / 2) / e->width / 2) / zoom * 10;
		e->ptr->x2 += ((e->height / 2) / e->width / 2) / zoom * 10;
		e->ptr->y1 += ((e->width / 2) / e->height / 2) / zoom * 10;
		e->ptr->y2 += ((e->width / 2) / e->height / 2) / zoom * 10;
	}
	else if (keycode == PAD_MINUS)
	{
		e->ptr->zoom_ratio /= 1.1;
		zoom = e->ptr->zoom_ratio;
		e->ptr->x1 += ((e->height / 2) / e->width / 2) / zoom * 10;
		e->ptr->x2 += ((e->height / 2) / e->width / 2) / zoom * 10;
		e->ptr->y1 += ((e->width / 2) / e->height / 2) / zoom * 10;
		e->ptr->y2 += ((e->width / 2) / e->height / 2) / zoom * 10;
	}
}

static void	key_move(int keycode, t_env *e)
{
	if (keycode == UP_ARROW)
	{
		e->ptr->y1 += 10 / (e->ptr->zoom_ratio * 20);
		e->ptr->y2 += 10 / (e->ptr->zoom_ratio * 20);
	}
	else if (keycode == DOWN_ARROW)
	{
		e->ptr->y1 -= 10 / (e->ptr->zoom_ratio * 20);
		e->ptr->y2 -= 10 / (e->ptr->zoom_ratio * 20);
	}
	else if (keycode == LEFT_ARROW)
	{
		e->ptr->x1 += 10 / (e->ptr->zoom_ratio * 20);
		e->ptr->x2 += 10 / (e->ptr->zoom_ratio * 20);
	}
	else if (keycode == RIGHT_ARROW)
	{
		e->ptr->x1 -= 10 / (e->ptr->zoom_ratio * 20);
		e->ptr->x2 -= 10 / (e->ptr->zoom_ratio * 20);
	}
}

int			mouse(int button, int x, int y, t_env *e)
{
	if (button == SCROLL_UP || button == LEFT_CLIC ||\
			button == SCROLL_DOWN || button == RIGHT_CLIC)
	{
		e->ptr->x1 += (((float)x - e->height / 2) / e->width / 2)
			/ e->ptr->zoom_ratio * 10;
		e->ptr->x2 += (((float)x - e->height / 2) / e->width / 2)
			/ e->ptr->zoom_ratio * 10;
		e->ptr->y1 += (((float)y - e->width / 2) / e->height / 2)
			/ e->ptr->zoom_ratio * 10;
		e->ptr->y2 += (((float)y - e->width / 2) / e->height / 2)
			/ e->ptr->zoom_ratio * 10;
	}
	if (button == SCROLL_UP || button == RIGHT_CLIC)
		e->ptr->zoom_ratio *= 1.1;
	if (button == SCROLL_DOWN || button == LEFT_CLIC)
		e->ptr->zoom_ratio /= 1.1;
	draw_img(e);
	return (0);
}

int			motion(int x, int y, t_env *e)
{
	if (x >= 0 && y >= 0 && x <= e->width && y <= e->height && e->stop_motion)
	{
		e->ptr->c.r = (float)x / (float)e->width * 4 - 2;
		e->ptr->c.im = (float)y / (float)e->height * 4 - 2;
		draw_img(e);
	}
	return (0);
}

int			key(int keycode, t_env *e)
{
	if (keycode == ESC || keycode == QUIT)
	{
		mlx_destroy_window(e->mlx, e->win);
		free(e->array);
		free(e->col_array);
		free(e);
		exit(0);
	}
	else if (keycode == PAD_0)
		e->stop_motion = !(e->stop_motion);
	if (keycode == RELOAD)
	{
		init_frac(e);
		frac_change(e->av[1], e);
		draw_img(e);
	}
	key_color_change(keycode, e);
	key_frac_change(keycode, e);
	key_scale(keycode, e);
	key_move(keycode, e);
	draw_img(e);
	return (0);
}
