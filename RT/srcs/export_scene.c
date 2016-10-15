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
	ft_fprintf(file, "%s :\n", CAM);
	ft_fprintf(file, "\tx : %f\n", cam->orig.x);
	ft_fprintf(file, "\ty : %f\n", cam->orig.y);
	ft_fprintf(file, "\tz : %f\n", cam->orig.z);
	ft_fprintf(file, "\tvx -> x : %f \n", cam->vx.x);
	ft_fprintf(file, "\tvx -> y : %f \n", cam->vx.y);
	ft_fprintf(file, "\tvx -> z : %f \n", cam->vx.z);
	ft_fprintf(file, "\tvy -> x : %f \n", cam->vx.x);
	ft_fprintf(file, "\tvy -> y : %f \n", cam->vx.y);
	ft_fprintf(file, "\tvy -> z : %f \n", cam->vx.z);
	ft_fprintf(file, "\tvz -> x : %f \n", cam->vx.x);
	ft_fprintf(file, "\tvz -> y : %f \n", cam->vx.y);
	ft_fprintf(file, "\tvz -> z : %f \n", cam->vx.z);
}

static void		display_light_prp(t_light *light, int file)
{
	ft_fprintf("%s :\n", LIGHT);
	ft_fprintf(file, "\tx : %f \n", light->orig.x);
	ft_fprintf(file, "\ty : %f \n", light->orig.y);
	ft_fprintf(file, "\tz : %f \n", light->orig.z);
	ft_fprintf(file, "\tIntensity : %f \n", light->instens);
	ft_fprintf(file, "\tRed : %f \n", light->color.red);
	ft_fprintf(file, "\tGreen : %f \n", light->color.green);
	ft_fprintf(file, "\tBlue : %f \n", light->color.blue);
}

void			export_scene(int file)
{
	t_obj		*obj;
	t_light		*light;

	ft_fprintf(file, "Width : %d\nHeight : %d\nRecurs : %d\nIf_name : %d\n\
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
