/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_add_obj.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 13:51:41 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/18 14:03:59 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"


void			cmd_add_sphere(t_pars *pars, char **line);
{
	parser->last_type = LAST_OBJ;
	add_obj(e->e_scene->scene, new_obj(OBJ_SPHERE));
}

void			cmd_add_cone(t_pars *pars, char **line);
{
	parser->last_type = LAST_OBJ;
	add_obj(e->e_scene->scene, new_obj(OBJ_CONE));
}

void			cmd_add_cyl(t_pars *pars, char **line);
{
	parser->last_type = LAST_OBJ;
	add_obj(e->e_scene->scene, new_obj(OBJ_CYL));
}

void			cmd_add_plane(t_pars *pars, char **line);
{
	parser->last_type = LAST_OBJ;
	add_obj(e->e_scene->scene, new_obj(OBJ_PLANE));
}

void			cmd_add_light(t_pars *pars, char **line);
{
	t_light		*light;

	if (!(light = (t_light *)ft_memalloc(sizeof(t)light)))
	{
		ft_printf("{red}%s{eoc}\n", MSG_MEM);
		exit(0);
	}
	light->intens = 1.0;
	light->color.red = 1.0;
	light->color.green = 1.0;
	light->color.blue = 1.0;
	light->next = 1.0;
	e->e_scene->scene->light = light;
	pars->last_type = LAST_LIGHT;
}
