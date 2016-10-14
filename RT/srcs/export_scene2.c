/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_scene2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 03:35:35 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/14 03:54:43 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		display_sphere_prp(t_obj *obj, int file)
{
	ft_printf(file, "%s\n", SPHERE);
	ft_printf(file, "\tx : %f\n", sphere->orig.x);
	ft_printf(file, "\ty : %f\n", sphere->orig.y);
	ft_printf(file, "\tz : %f\n", sphere->orig.z);
	ft_printf(file, "\tRot x : %f\n", sphere->rot_x);
	ft_printf(file, "\tRot y : %f\n", sphere->rot_y);
	ft_printf(file, "\tRot z : %f\n", sphere->rot_z);
	ft_printf(file, "\tRadius : %f\n", sphere->radius);
	ft_printf(file, "\tColor : %f\n", sphere->color.color);
	ft_printf(file, "\tAmbient : %f\n", sphere->ambient);
	ft_printf(file, "\tDiffuse : %f\n", sphere->diffuse);
	ft_printf(file, "\tMirror : %f\n", sphere->mirror);
	ft_printf(file, "\tReflec : %f\n", sphere->reflec);
	ft_printf(file, "\tRefrac : %f\n", sphere->refrac);
}

void		display_cone_prp(t_obj *obj, int file)
{
	ft_printf(file, "%s\n", CONE);
	ft_printf(file, "\tx : %f\n", cone->orig.x);
	ft_printf(file, "\ty : %f\n", cone->orig.y);
	ft_printf(file, "\tz : %f\n", cone->orig.z);
	ft_printf(file, "\tNormal x : %f\n", cone->normal.x);
	ft_printf(file, "\tNormal y : %f\n", cone->normal.y);
	ft_printf(file, "\tNormal z : %f\n", cone->normal.z);
	ft_printf(file, "\tRadius : %f\n", cone->radius);
	ft_printf(file, "\tColor : %f\n", cone->color.color);
	ft_printf(file, "\tAmbient : %f\n", cone->ambient);
	ft_printf(file, "\tDiffuse : %f\n", cone->diffuse);
	ft_printf(file, "\tMirror : %f\n", cone->mirror);
	ft_printf(file, "\tReflec : %f\n", cone->reflec);
	ft_printf(file, "\tRefrac : %f\n", cone->refrac);
}

void		display_cyl_prp(t_obj *obj, int file)
{
	ft_printf(file, "%s\n", CYL);
	ft_printf(file, "\tx : %f\n", cyl->orig.x);
	ft_printf(file, "\ty : %f\n", cyl->orig.y);
	ft_printf(file, "\tz : %f\n", cyl->orig.z);
	ft_printf(file, "\tNormal x : %f\n", cyl->normal.x);
	ft_printf(file, "\tNormal y : %f\n", cyl->normal.y);
	ft_printf(file, "\tNormal z : %f\n", cyl->normal.z);
	ft_printf(file, "\tRadius : %f\n", cyl->radius);
	ft_printf(file, "\tColor : %f\n", cyl->color.color);
	ft_printf(file, "\tAmbient : %f\n", cyl->ambient);
	ft_printf(file, "\Diffuse : %f\n", cyl->diffuse);
	ft_printf(file, "\tMirror : %f\n", cyl->mirror);
	ft_printf(file, "\tReflec : %f\n", cyl->reflec);
	ft_printf(file, "\tRefrac : %f\n", cyl->refrac);
}

void		display_plane_prp(t_obj *obj, int file)
{
	ft_printf(file, "%s\n", PLANE);
	ft_printf(file, "\tx : %f\n", plane->orig.x);
	ft_printf(file, "\ty : %f\n", plane->orig.y);
	ft_printf(file, "\tz : %f\n", plane->orig.z);
	ft_printf(file, "\tNormal x : %f\n", plane->normal.x);
	ft_printf(file, "\tNormal y : %f\n", plane->normal.y);
	ft_printf(file, "\tNormal z : %f\n", spher-normal.z);
	ft_printf(file, "\tColor : %f\n", plane->color.color);
	ft_printf(file, "\tAmbient : %f\n", plane->ambient);
	ft_printf(file, "\Diffuse : %f\n", plane->diffuse);
	ft_printf(file, "\tMirror : %f\n", plane->mirror);
	ft_printf(file, "\tReflec : %f\n", plane->reflec);
	ft_printf(file, "\tRefrac : %f\n", plane->refrac);
}
