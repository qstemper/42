/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 02:36:01 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/14 03:42:05 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		display_cam_prp(t_cam *cam, int file)
{
	ft_printf(file, "%s :\n", CAM);
	ft_printf(file, "\tx : %f\n", cam->orig.x);
	ft_printf(file, "\ty : %f\n", cam->orig.y);
	ft_printf(file, "\tz : %f\n", cam->orig.z);
	ft_printf(file, "\tvx -> x : %f \n", cam->vx.x);
	ft_printf(file, "\tvx -> y : %f \n", cam->vx.y);
	ft_printf(file, "\tvx -> z : %f \n", cam->vx.z);
	ft_printf(file, "\tvy -> x : %f \n", cam->vx.x);
	ft_printf(file, "\tvy -> y : %f \n", cam->vx.y);
	ft_printf(file, "\tvy -> z : %f \n", cam->vx.z);
	ft_printf(file, "\tvz -> x : %f \n", cam->vx.x);
	ft_printf(file, "\tvz -> y : %f \n", cam->vx.y);
	ft_printf(file, "\tvz -> z : %f \n", cam->vx.z);
}

static void		display_light_prp(t_light *light, int file)
{
	ft_printf("%s :\n", LIGHT);
	ft_printf(file, "\tx : %f \n", light->orig.x);
	ft_printf(file, "\ty : %f \n", light->orig.y);
	ft_printf(file, "\tz : %f \n", light->orig.z);
	ft_printf(file, "\tIntensity : %f \n", light->instens);
	ft_printf(file, "\tRed : %f \n", light->color.red);
	ft_printf(file, "\tGreen : %f \n", light->color.green);
	ft_printf(file, "\tBlue : %f \n", light->color.blue);
}

void			export_scene(int file)
{
	t_obj		*obj;
	t_light		*light;

	ft_printf(file, "Width : %d\nHeight : %d\nRecurs : %d\nIf_name : %d\n\
			Diaph : %d\n", env->e_scene.scene.width, \
			env->e_scene.scene.height, env->e_scene.scene.recurs, \
			env->e_scene.scene.if_name, env->e_scene.scene.diaph);
	display_cam_prp(&env->e_scene.scene.cam, file);
	light = env->e_scene.scene.light;
	while (light->next)
		display_light_prp(light, file);
	obj = env->e_scene.scene.obj;
	while (obj)
	{
	if (obj->type == OBJ_SPHERE)
		display_sphere_prp(obj, file);
	else if (obj->type == OBJ_PLANE)
		display_plane_prp(obj, file);
	else if (obj->type == OBJ_CONE)
		display_cone_prp(obj, file);
	else if (obj->type == OBJ_CYL)
		display_cyl_prp(obj, file);
	obj = obj->next;
	}
}
