/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 07:38:13 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/13 08:49:37 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include <math.h>

typedef struct	s_cam
{
	t_point		orig;
	t_vect		vx;
	t_vect		vy;
	t_vect		vz;
}				t_cam;

/*
***							move_cam.c
*/

void			cam_rot_x(t_cam *cam, float angle);
void			cam_rot_y(t_cam *cam, float angle);
void			cam_rot_z(t_cam *cam, float angle);
void			cam_trans(t_cam *cam, float x, float y, float z);
void			cam_trans_vect(t_cam *cam, t_vect *v, float coef);
void			cam_move_to(t_cam *cam, float x, float y, float z);

/*
***							init_cam.c
*/

void			init_cam(t_cam *cam, float x, float y, float z);
void			init_cam_angle(t_cam *cam, float y, float z);
void			update_render_cam(t_cam *res, t_cam *cam);

#endif
