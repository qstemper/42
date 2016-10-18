/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_shade2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/16 16:05:39 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/18 07:37:54 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		reflect_light(t_sup_vect *vect)
{
	vect->reflect_light.x = 2 * vect_dot(vect->normal, vect->light_vect) *\
				vect->normal.x - vect->light_vect.x;
	vect->reflect_light.y = 2 * vect_dot(vect->normal, vect->light_vect) *\
				vect->normal.y - vect->light_vect.y;
	vect->reflect_light.z = 2 * vect_dot(vect->normal, vect->light_vect) *\
				vect->normal.z - vect->light_vect.z;
	normalize_vect(vect->reflect_light);

}

static void		vect_light(t_sup_vect, t_light *light, t_point intersec)
{
	vect->light_vect.x = light->orig.x - intersec.x;
	vect->light_vect.y = light->orig.y - intersec.y;
	vect->light_vect.z = light->orig.z - intersec.z;
	normalize_vect(vect->light_vec);
}

static void		get_phong_normal(t_sup_vect *vect, \
		t_point *intersec, t_ray *ray)
{
	if (ray->near->type == OBJ_SPHERE)
	{
		vect->normal.x = intersec.x - ray->near->orig.x;
		vect->normal.y = intersec.y - ray->near->orig.y;
		vect->normal.z = intersec.z - ray->near->orig.z;
	}
	else if (ray->near->type == OBJ_CYL)
		get_cyl_normal(vect->norm, ray->near, intersec);
	else if (ray->near->type == OBJ_CONE)
		get_cyl_normal(vect->norm, ray->near, intersec);
	else
		vect->normal = ray->near->normal;
	normalize_vect(vect->normal);
}

static void		phong_color(float val, t_ray *ray, t_light *light)
{
	ray->color.red += val * ((float)ray->near->color.red * \
			   ray->near->diffuse * light->color.red * \
			   light->intens / 255.0);
	ray->color.green += val * ((float)ray->near->color.green * \
			    ray->near->diffuse * light->color.green * \
			    light->intens / 255.0);
	ray->color.blue += val * ((float)ray->near->color.blue * \
			    ray->near->diffuse * light->color.blue * \
			    light->intens / 255.0);
}

float			phong_light(t_ray *ray, t_env *e)
{
	t_sup_vect	*vect;
	t_point		intersec;
	float		val;
	t_light		*light;
	float		spec;

	intersec = pt_ray_intersec(ray, ray->inter_t);
	get_phong_normal(vect, &intersec, ray);
	light = e->e_scene->light;
	while (light->next)
	{
		if (pt_lighted(ray->near, intersec, light))
		{
			vect_light(vect, light, intersec);
			val = vect_dot(vect->normal, vect->light_vect);
			if (val > 0)
				phong_color(val, ray, light);
			reflect_light(vect, light);
			phong_cam(vect, intersec, e);
			spec = ray->near->spec * pow(fmax(0, \
				vect_dot(vect->reflect_light, vect->cam)), 500);
			phong_color_2(ray, spec, light);
		}
	}
	return (val);
}
