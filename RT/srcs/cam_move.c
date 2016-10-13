/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cam.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 08:26:06 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/13 15:05:59 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		cam_rot_x(t_cam *cam, float angle)
{
	t_vect	y_cache;
	t_vect	z_cache;

	ft_memcpy(&y_cache, &cam->vy, sizeof(t_vect));
	ft_memcpy(&z_cache, &cam->vz, sizeof(t_vect));
	vect_add(&cam->vz, &y_cache, angle);
	vect_add(&cam->vy, &z_cache, -angle);
	norm_vect(&cam->vz);
	norm_vect(&cam->vy);
}

void		cam_rot_y(t_cam *cam, float angle)
{
	t_vect	x_cache;
	t_vect	z_cache;

	ft_memcpy(&x_cache, &cam->vx, sizeof(t_vect));
	ft_memcpy(&z_cache, &cam->vz, sizeof(t_vect));
	vect_add(&cam->vz, &x_cache, angle);
	vect_add(&cam->vx, &z_cache, -angle);
	norm_vect(&cam->vz);
	norm_vect(&cam->vx);
}

void		cam_rot_z(t_cam *cam, float angle)
{
	t_vect	x_cache;
	t_vect	y_cache;

	ft_memcpy(&x_cache, &cam->vx, sizeof(t_vect));
	ft_memcpy(&y_cache, &cam->vy, sizeof(t_vect));
	vect_add(&cam->vy, &x_cache, -angle);
	vect_add(&cam->vx, &y_cache, angle);
	norm_vect(&cam->vy);
	norm_vect(&cam->vx);
}

void	cam_trans(t_cam *cam, float x, float y, float z)
{
	cam->orig.x += x;
	cam->orig.y += y;
	cam->orig.z += z;
}

void	cam_trans_vect(t_cam *cam, t_vect *v, float coef)
{
	cam->orig.x += v->x * coeff;
	cam->orig.y += v->y * coeff;
	cam->orig.z += v->z * coeff;
}
