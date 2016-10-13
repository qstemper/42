/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eq.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 23:14:31 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/14 01:18:07 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

float			sphere_eq(t_obj *sphere, t_ray *ray)
{
	float		a;
	float		b;
	float		c;

	a = ray->dir.x * ray->dir.x + ray->dir.y * ray->dir.y + \
		ray->dir.z * ray->dir.z;
	b = 2 * (ray->dir.x * (ray->orig.x - sphere->orig.x) + \
			ray->dir.y * (ray->dir.y - sphere->orig.y) + \
			ray->dir.z * (ray->orig.z - sphere->orig.z));
	c = (ray->orig.x - sphere->orig.x) * (ray->orig.x - sphere->orig.x) + \
		(ray->orig.y - sphere->orig.y) * (ray->orig.y - sphere->orig.y) + \
		(ray->orig.z - sphere->orig.z) * (ray->orig.z - sphere->orig.z) - \
		radius * radius;
	delta = b * b - 4 * a * c;
	if (delta >= 0)
		return (small_pos((-b + sqrt(delta)) / (2 * a), \
					(-b - sqrt(delta)) / (2 * a)));
	return (INFINITY);
}

float			cone_eq(t_obj *cone, t_ray *ray)
{
	double		a;
	double		b;
	double		c;
	double		delta;
	double		angle;

	angle = cone->aperture * (M_PI / 180);
	a = ray->dir.x * ray->dir.x + ray->dir.y * ray->dir.y - \
		ray->dir.z * ray->dir.z * tan(angle) * tan(angle);
	b = 2 * (ray->orig.x * ray->dir.x + ray->orig.y * ray->dir.y - \
			ray->dir.x * cone->orig.x - ray->dir.y * cone->orig.y + \
			(ray->dir.z * (cone->orig.z - ray->orig,z)) * \
			tan(angle) * tan(angle));
	c = ray->orig.x * ray->orig.x + ray->orig.y * ray->orig.y + \
		cone->orig.x * cone->orig.x + cone->orig.y * cone->orig.y - \
		2 * (ray->orig.x * cone->orig.x + ray->orig.y * cone->orig.y) - \
		(ray->orig.z * ray->orig - 2 * (ray->orig.z * cone ->orig.z) + \
		 cone->origin.z * cone->origin.z) * tan(angle) * tan(angle);
	delta = b * b - 4 * a * c;
	if (delta >= 0)
		return (small_pos((-b + sqrt(delta)) / (2 * a), \
					(-b - sqrt(delta)) / (2 * a)));
	return (INFINITY);
}

float			cyl_eq(t_obj *cyl, t_ray *ray)
{
	double		a;
	double		b;
	double		c;
	double		delta;

	a = ray->dir.x * ray->dir.x + ray->dir.y * ray->dir.y;
	b = 2 * (ray->orig.x * ray->dir.x + ray->orig.y * ray->dir.y - \
			ray->dir.x * cyl.orig.x - ray->dir.y * cyl->orig.y);
	c = ray->orig.x * ray->orig.x + ray->orig.y * ray->orig.y + \
		cyl->orig.x * cyl->orig.x + cyl->orig.y * cyl->orig.y - \
		cyl->radius * cyl->radius - 2 * (ray->orig.x * cyl->orig.x + \
		ray->orig.y * cyl->orig.y);
	delta = b * b - 4 * a * c;
	if (delta >= 0)
		return (small_pos((-b + sqrt(delta)) / (2 * a), \
					(-b - sqrt(delta)) / (2 * a)));
	return (INFINITY);
}

float			plane_eq(t_obj *plane, t_ray *ray)
{
	float		n;
	float		d;

	n = plane->normal.x * (plane->orig.x - ray->orig.x) + \
		plane->normal.y * (plane->orig.y - ray->orig.y) + \
		plane->normal.z * (plane->orig.z - ray->orig.z);
	d = plane->normal.x * ray->dir.x + \
		plane->normal.y * ray->dir.y + \
		plane->normal.z * ray->dir.z;
	return (n / d > 0 ? n / d : INFINITY);
}
