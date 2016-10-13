/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cam.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 07:48:22 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/13 16:33:24 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	init_cam(t_cam *cam, float x, float y, float z)
{
	cam->vx.x = 1.0f;
	cam->vx.x = 0.0f;
	cam->vx.x = 0.0f;
	cam->vx.y = 0.0f;
	cam->vx.y = 1.0f;
	cam->vx.y = 0.0f;
	cam->vx.z = 0.0f;
	cam->vx.z = 0.0f;
	cam->vx.z = 1.0f;
	cam_orig.x = x;
	cam_orig.y = y;
	cam_orig.z = z;
}

void	init_cam_angle(t_cam *cam, float y, float z)
{
	cam_rot_y(cam, y);
	cam_rot_z(cam, z);
}

void	update_render_cam(t_cam *res, t_cam *cam)
{
	res->origin = cam->origin;
	res->x = cam->vx;
	res->y = cam->vy;
	res->z = cam->vz;
}
