/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 15:27:01 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/16 14:48:38 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

typedef struct		s_ray
{
	t_point			orig;
	t_vect			dir;
	float			intens;
	t_light_color	color;
	t_object		*near;
	float			inter_t;
}					t_ray;

/*
***					chg_ray.c
*/

void				chg_ray(t_ray *ray1, t_ray *ray2, t_obj *obj1, t_obj *obj2);

 /*
***					eq.c
*/

float				sphere_eq(t_obj *sphere, t_ray *ray);
float				plane_eq(t_obj *plane, t_ray *ray);
float				cyl_eq(t_obj *cyl, t_ray *ray);
float				cone_eq(t_obj *cone, t_ray *ray);

/*
***					get_norm.c
*/

void				get_cyl_norm(t_vect *norm, t_obj *cyl, t_point *intersec);
void				get_cone_norm(t_vect *norm, t_obj *cone, t_point *intersec);

/*
***					small_pos.c
*/

float				small_pos(float a, float b);

#endif
