/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 14:59:08 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/16 15:50:23 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# define OBJ_SPHERE	0
# define OBJ_CONE	1
# define OBJ_CYL	2
# define OBJ_CONE	3

typedef struct			s_obj
{
		char			*name;
		int				type;
		t_point			orig;
		union
		{
			struct
			{
				float	rot_x;
				float	rot_y;
				float	rot_z;
			};
			t_vect		normal;
		};
		t_color			color;
		float			opacity;
		float			ambient;
		float			diffuse;
		float			mirror;
		float			reflect;
		float			refrac;
		float			index_refract;
		union
		{
			float		radius;
			float		aperture;
		};
		struct_s obj	*next;
}						t_obj;

/*
***									obj.c
*/

void					remove_obj(t_scene *scene, t_obj *obj);
void					duplicate_obj(t_obj *obj);
void					add_obj(t_scene *scene, t_obj *obj);
t_obj					*new_obj(int type);

#endif
