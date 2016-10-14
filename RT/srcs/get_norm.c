/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_norm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 01:20:56 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/14 01:39:00 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			get_cyl_norm(t_vect *norm, t_obj *cyl, t_point *intersec)
{
	t_vect		v;
	t_vect		projection;
	float		dot;

	if (vect_norm(&cyl->normal) - 1 > 0.05)
		normalize_vect(&cyl->normal);
	v.x = intersec->x - cyl->orig.x;
	v.y = intersec->y - cyl->orig.y;
	v.z = intersec->z - cyl->orig.z;
	dot = vect_dot(&v, &cyl->normal);
	projection.x = dot * cyl->normal.x;
	projection.y = dot * cyl->normal.y;
	projection.z = dot * cyl->normal.z;
	norm->x = v.x - projection.x;
	norm->x = v.y - projection.y;
	norm->x = v.z - projection.z;
	normalize_vect(norm);
}

void			get_cone_norm(t_vect *norm, t_obj *cyl, t_point *intersec)
{
	t_vect		v;
	t_vect		projection;
	float		dot;

	if (vect_norm(&cone->normal) - 1 > 0.05)
		normalize_vect(&cone->normal);
	v.x = intersec->x - cone->orig.x;
	v.y = intersec->y - cone->orig.y;
	v.z = intersec->z - cone->orig.z;
	dot = vect_dot(&v, &cone->normal);
	projection.x = dot * cone->normal.x;
	projection.y = dot * cone->normal.y;
	projection.z = dot * cone->normal.z;
	norm->x = v.x - projection.x;
	norm->x = v.y - projection.y;
	norm->x = v.z - projection.z;
	normalize_vect(norm);
}
