/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 01:39:24 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/14 01:54:59 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vect		matrix_vect_prod(float matrix[9], t_vect *v)
{
	t_vect	vector;

	vector.x = matrix[0] * v->x + matrix[1] * v->y + matrix[2] * v->z;
	vector.y = matrix[3] * v->x + matrix[4] * v->y + matrix[5] * v->z;
	vector.z = matrix[6] * v->x + matrix[7] * v->y + matrix[8] * v->z;
	return (vector);
}

t_point		matrix_pt_prod(float matrix[9], t_point *a)
{
	t_point	b;

	b.x = matrix[0] * a->x + matrix[1] * a->y + matrix[2] * a->z;
	b.y = matrix[3] * a->x + matrix[4] * a->y + matrix[5] * a->z;
	b.z = matrix[6] * a->x + matrix[7] * a->y + matrix[8] * a->z;
	return (b);
}

void		transfo_matrix(float matrix[9], t_vect *vx, t_vect *vy, t_vect *vz)
{
	matrix[0] = vx->x;	
	matrix[1] = vy->x;	
	matrix[2] = vz->x;	
	matrix[3] = vx->y;	
	matrix[4] = vy->y;	
	matrix[5] = vz->y;	
	matrix[6] = vx->z;	
	matrix[7] = vy->z;	
	matrix[8] = vz->z;	
}

void		invert_matrix(float matrix [9], float invert_matrix[9])
{
	float	delta;

	delta = matrix[0] * (matrix[4] * matrix[8] - matrix[7] * matrix[5]) - \
			matrix[1] * (matrix[3] * matrix[8] - matrix[6] * matrix[5]) + \
			matrix[2] * (matrix[3] * matrix[7] - matrix[6] * matrix[4]);
	if (fabs(delta) < 0.0005)
		return ;
	invert_matrix[0] = (matrix[4] * matrix[8] - matrix[7] * matrix[5]) / delta;
	invert_matrix[1] = -(matrix[1] * matrix[8] - matrix[2] * matrix[7]) / delta;
	invert_matrix[2] = (matrix[1] * matrix[5] - matrix[2] * matrix[4]) / delta;
	invert_matrix[3] = -(matrix[3] * matrix[8] - matrix[6] * matrix[5]) / delta;
	invert_matrix[4] = (matrix[0] * matrix[8] - matrix[2] * matrix[6]) / delta;
	invert_matrix[5] = -(matrix[0] * matrix[5] - matrix[2] * matrix[3]) / delta;
	invert_matrix[6] = (matrix[3] * matrix[7] - matrix[4] * matrix[6]) / delta;
	invert_matrix[7] = -(matrix[0] * matrix[7] - matrix[1] * matrix[6]) / delta;
	invert_matrix[8] = (matrix[0] * matrix[4] - matrix[3] * matrix[1]) / delta;
}
