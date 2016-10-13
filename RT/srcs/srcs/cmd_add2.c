/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_add2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 08:21:05 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/13 08:55:31 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			add_sphere()
{
	add_obj(env->scene, new_obj(OBJ_SPHERE));
	env->scene->obj->orig.x = env->scene->cam.orig.x + env->scene->cam.vx.x * 4;
	env->scene->obj->orig.y = env->scene->cam.orig.y + env->scene->cam.vx.y * 4;
	env->scene->obj->orig.z = env->scene->cam.orig.z + env->scene->cam.vx.z * 4;
	env->scene->obj->rad = 1;
	env->scene->obj->color.color = 0xFFFAEFFF;
	env->scene->obj->ambient = 0.2;
	env->scene->obj->diffuse = 0.4;
	env->scene->obj->specular = 0.2;
	env->scene->obj->reflect = 0.7;
	env->last_scene_change = clock();
}

void			add_cyl()
{
	add_obj(env->scene, new_obj(OBJ_CYL));
	env->scene->obj->orig.x = env->scene->cam.orig.x + env->scene->cam.vx.x * 4;
	env->scene->obj->orig.y = env->scene->cam.orig.y + env->scene->cam.vx.y * 4;
	env->scene->obj->orig.z = env->scene->cam.orig.z + env->scene->cam.vx.z * 4;
	env->scene->obj->normal.z = 1;
	env->scene->obj->rad = 2.2;
	env->scene->obj->color.color = 0xFFFFFFFF;
	env->scene->obj->ambient = 0.1;
	env->scene->obj->diffuse = 0.8;
	env->scene->obj->specular = 0.4;
	env->scene->obj->reflect = 0.7;
	env->last_scene_change = clock();

}

void			add_cone()
{
	add_obj(env->scene, new_obj(OBJ_CONE));
	env->scene->obj->orig.x = env->scene->cam.orig.x + env->scene->cam.vx.x * 4;
	env->scene->obj->orig.y = env->scene->cam.orig.y + env->scene->cam.vx.y * 4;
	env->scene->obj->orig.z = env->scene->cam.orig.z + env->scene->cam.vx.z * 4;
	env->scene->obj->normal.z = 1;
	env->scene->obj->rad = 1;
	env->scene->obj->color.color = 0xFFFFFFFF;
	env->scene->obj->aperture = 22;
	env->scene->obj->ambient = 0.1;
	env->scene->obj->diffuse = 0.8;
	env->scene->obj->specular = 0.4;
	env->scene->obj->reflect = 0.7;
	env->last_scene_change = clock();

}

void			add_plane()
{
	add_obj(env->scene, new_obj(OBJ_PLANE));
	env->scene->obj->orig.x = env->scene->cam.orig.x + env->scene->cam.vx.x * 4;
	env->scene->obj->orig.y = env->scene->cam.orig.y + env->scene->cam.vx.y * 4;
	env->scene->obj->orig.z = env->scene->cam.orig.z + env->scene->cam.vx.z * 4;
	env->scene->obj->normal.z = 1;
	env->scene->obj->color.color = 0xFFFFFFFF;
	env->scene->obj->ambient = 0.1;
	env->scene->obj->diffuse = 0.8;
	env->scene->obj->specular = 0.4;
	env->scene->obj->reflect = 0.7;
	env->last_scene_change = clock();

}

void			add_light()
{
	t_light		*light;

	if (!(light = (t_light *)malloc(sizeof(t_light))))
	{
		ft_printf("{red}%s{eoc}", MSG_MEM);
		return ;
	}
	light->type = 0;
	light->orig.x = env->scene->cam.orig.x + env->scene->cam.vx.x * 4;
	light->orig.y = env->scene->cam.orig.y + env->scene->cam.vx.y * 4;
	light->orig.z = env->scene->cam.orig.z + env->scene->cam.vx.z * 4;
	light->intens = 1.0;
	light->color.red = 1.0;
	light->color.green = 1.0;
	light->color.blue = 1.0;
	light->next = env->scene->light;
	env->scene->light = light;
	env->last_scene_change = clock();
}
