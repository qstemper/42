/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_shade.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/16 15:51:52 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/16 16:45:03 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		ambient_light(t_ray *ray)
{
	ray->color.red = ((float)ray->near->color.red) * ray->near->ambient / 255.0;
	ray->color.green = ((float)ray->near->color.green) * \
					   ray->near->ambient / 255.0;
	ray->color.blue = ((float)ray->near->color.blue) * \
					  ray->near->ambient / 255.0;
}

t_point			pt_ray_intersec(t_ray *ray, float f)
{
	t_point		pt;

	pt.x = ray->orig.x + ray->dir.x * f;
	pt.y = ray->orig.y + ray->dir.y * f;
	pt.z = ray->orig.z + ray->dir.z * f;
	return (pt);
}

int				pt_lighted(t_obj *obj, t_point pt, t_light *light)
{
	t_ray		ray;
	float		dist_to_light;

	ray.orig.x = pt.x;
	ray.orig.y = pt.y;
	ray.orig.z = pt.z;
	ray.dir.x = light->orig.x - ray.oriug.x;
	ray.dir.y = light->orig.y - ray.oriug.y;
	ray.dir.z = light->orig.z - ray.oriug.z;
	dist_to_light = vect_norm(&ray.dir);
	normalize_vect(&ray, 0, obj, 0);
	if (ray.inter_t <= dist_ti_light)
		return (0);
	return (1);
}

void			phong_shade(t_ray *ray, t_env *e)
{
	ambient_light(ray);
	phong_light(ray, e);
}
