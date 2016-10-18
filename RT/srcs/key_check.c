/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 03:55:55 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/18 09:14:44 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		check_key_move(t_key *e)
{
	if (e->event.key.up)
		cam_rot_y(&env->e_scene.cam, -K_ROT);
	if (e->event.key.down)
		cam_rot_y(&env->e_scene.cam, K_ROT);
	if (e->event.key.left)
		cam_rot_y(&env->e_scene.cam, K_ROT);
	if (e->event.key.right)
		cam_rot_y(&env->e_scene.cam, K_ROT);
	if (e->event.key.page_up)
		cam_rot_y(&env->e_scene.cam, K_ROT);
	if (e->event.key.page_down)
		cam_rot_y(&env->e_scene.cam, K_ROT);
	if (e->event.key.num_plus)
		cam_rot_y(&env->e_scene.cam, K_ROT);
	if (e->event.key.num_minus)
		cam_rot_y(&env->e_scene.cam, K_ROT);
}

static void		check_wa(t_key *e)
{
	if (e->event.key.w)
	{
		if (env->event.select_obj)
			vect_add((t_vect *)&(env->event.select_obj.orig), \
				&env->e_scene.scene.cam.vx, K_MOVE);
		cam_trans_vect(&env->e_scene.scene.cam, \
				&env->e_scene.scene.cam.vx, K_MOVE);
	}
	if (e->event.key.a)
	{
		if (env->event.select_obj)
			vect_add((t_vect *)&(env->event.select_obj.orig), \
				&env->e_scene.scene.cam.vy, K_MOVE);
		cam_trans_vect(&env->e_scene.scene.cam, \
				&env->e_scene.scene.cam.vy, K_MOVE);
	}
}

static void		check_sd(t_key *e)
{
	if (e->event.key.s)
	{
		if (env->event.select_obj)
			vect_add((t_vect *)&(env->event.select_obj.orig), \
				&env->e_scene.scene.cam.vx, -K_MOVE);
		cam_trans_vect(&env->e_scene.scene.cam, \
				&env->e_scene.scene.cam.vx, -K_MOVE);
	}
	if (e->event.key.d)
	{
		if (env->event.select_obj)
			vect_add((t_vect *)&(env->event.select_obj.orig), \
				&env->e_scene.scene.cam.vy, -K_MOVE);
		cam_trans_vect(&env->e_scene.scene.cam, \
				&env->e_scene.scene.cam.vy, -K_MOVE);
	}
	env->frame.scene_refresh = clock();
}

void			check_key(t_env *e)
{
	check_keymove(e);
	check_ws(e);
	check_ad(e);
}
