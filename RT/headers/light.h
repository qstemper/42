/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 14:50:04 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/16 15:50:41 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "rt.h"

# define LIGHT_DOT		0
# define LIGHT_SPHERE	1


typedef union		u_light_color
{
	struct
	{
		float		red;
		float		green;
		float		blue;
	};
	struct
	{
		float		r;
		float		g;
		float		b;
	};
}					t_light_color;

typedef struct		s_light
{
	char			*light;
	int				type;
	t_point			orig;
	float			intens;
	t_vect			dir;
	t_obj			*obj;
	float			aperture;
	t_light_color	color;
	struct s_light	*next;
}					t_light;

/*
***									obj.c
*/

void				remove_light(t_scene *scene, t_light *light);
