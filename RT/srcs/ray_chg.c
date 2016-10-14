/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chg_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 21:50:35 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/13 23:13:50 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static t_vect	chg_ray_vz_x(t_vect *v1, t_vect *v2)
{
	v1->x = 0;
	v1->y = 1;
	v1->z = 0;
	v2->x = 0;
	v2->y = 0;
	v2->z = 1;
}

static t_vect	chg_ray_vz_x(t_vect *v1, t_vect *v2)
{
	v1->x = 0;
	v1->y = 0;
	v1->z = 1;
	v2->x = 1;
	v2->y = 0;
	v2->z = 0;
}

static void		chg_ray_vect(t_vect *v1, t_vect *v2, t_vect *v3)
{
	normalize_vect(v3);
	v2->x = -v3->y;
	v2->y = v3->x;
	v2->z = 0;
	normalize_vect(v2);
	vx = vect_prod(v2, v3);
	normalize_vect(v1);
}

void			chg_ray(t_ray *ray1, t_ray *ray2, t_obj *obj1, t_obj *obj2)
{
	float		matrix[9];
	float		invert_matrix[9];
	t_vect		vx;
	t_vext		vy;
	t_vect		vz;

	vz = obj->normal;
	if (vz.x == 0 && vz.y == 0 && (vz.z == 1 || vz.z == -1))
		return ;
	if ((vz.x == 1 || vz.x == -1) && vz.y == 0 && vz.z == 0)
		chg_ray_vz_x(&vx, &vy);
	else if(vz.x == 1 && (vz.x == 1 || vz.y == -1) && vz.z == 0)
		chg_ray_vz_y(&vx, &vy);
	else
		chg_ray_vect(&vx, &vy, &vz);
	transfo_matrix(matrix, &vx, &vy, &vz);
	invert_matrix(matrix, invert_matrix);
	ray2->orig = matrix_pt_prod(invert_matrix, &ray->orig);
	obj2->orig = matrix_pt_prod(invert_matrix, &obj->orig);
	ray2->dir = matrix_vect_prod(invert_matrix, &ray->dir);
}
