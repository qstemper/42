/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/16 14:22:55 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/16 15:25:40 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	motion_event_key2(int x, int y, t_env *e)
{
	vect_add((t_vect *)(e->event.select_obj.orig), \
			e->e_scene.scene.cam.vy, \
			(e->event.x - x) * coef);
	if (e->event.key.ctrl)
		vect_add((t_vect *)(e->event.select_obj.orig), \
				e->e_scene.scene.cam.vx, \
				(e->event.y - y) * coef);
	else
		vect_add((t_vect *)(e->event.select_obj.orig), \
				e->e_scene.scene.cam.vz, \
				(e->event.y - y) * coef);

}

static void	motion_event_key(int x, int y, t_env *e)
{
	if (e->event.key.alt)
	{
		e->event.select_obj.radius += fmin((float)(x - e->event.x), \
				(float)(y - e->event.y)) * coef;
		if (e->event.select_obj.radius < 0)
			e->event.select_obj.radius *= -1;
	}
	else if (e->event.key.tab)
	{
		normalize_vect(e->event.select_obj.normal);
		vect_rot_x(e->event.select_obj.normal, -cos(x - e->event.x) \
				/ (5000  * coef));
	}
	else
		motion_event_key2(x, y, e);
}

int			motion_notify(int x, int y, t_env *e)
{
	float	coef;

	if (e->frame.block)
		return (0);
	if (e->event.mouse)
	{
		if (e->event.select_obj)
		{
			coef = dist_pt(e->event.select_obj.orig, \
					e->e_scene.scene.cam.orig) * 0.001;
			motion_event_key(x, y, e);

		}
		e->frame.scene_refresh = clock();
	}
	e->event.x = x;
	e->event.y = y;
	return (0);
}

int			mouse_press(int button, int x, int y, t_env *e)
{
	t_ray	ray;

	if (e->frame.block)
		return (0);
	ray = get_ray_from_point(x, y);
	trace_ray(&ray, 0, NULL, 0);
	if (button == LEFT_C)
		e->event.mouse = 1;
	if (ray.inter_t != INFINITY)
	{
		if (button == L_CLICK && e->event.key.del)
		{
			remove_obj(e->e_scene.scene, ray.near);
			update_img(e);
		}
		else 
		{
			if (button == RIGHT_C)
				ft_printf("Selected Obj : %u.\n", (unsigned int)ray.near);
			e->event.select_obj = ray.near;
		}
	}
	return (0);
}

int			mouse_release(int button, int x, int y, t_env *e)
{
	(void)x;
	(void)y;
	if (e->frame.block)
		return (0);
	if (button == L_CLICK)
	{
		e->event.select_obj = NULL;
		e->event.mouse = 0;
	}
	return (0);
}
