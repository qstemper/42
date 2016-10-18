/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_shade3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 07:37:42 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/18 07:37:46 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	phong_cam(t_sup_vect *vect, t_point intersec, t_env *e)
{
	vect->cam.x = e->e_scene->cam.orig.x - intersec.x;
	vect->cam.y = e->e_scene->cam.orig.y - intersec.y;
	vect->cam.z = e->e_scene->cam.orig.z - intersec.z;
	normalize_vect(vect->cam);
}

void	phong_color_2(t_ray *ray, float spec, t_light *light)
{
	if (spec > 0)
	{
		ray->color.red += spec * (ray->near->spec * light->intens);
		ray->color.green += spec * (ray->near->spec * light->intens);
		ray->color.blue += spec * (ray->near->spec * light->intens);
	}
}
