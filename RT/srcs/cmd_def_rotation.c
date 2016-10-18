/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_def_rotation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 18:06:31 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/18 18:21:33 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		cmd_def_rot_x(t_pars *pars, char **line)
{
	if (pars->last_type == LAST_OBJ)
		e->e_scene->scene->obj->rot_x = ft_atoi([0]);
	else if (parser->last_type == LAST_LIGHT)
		e->e_scene->scene->light->dir.x = ft_atoi([0]);
	else
		ft_printf("%s rot x", MSG_CMD_DEF);
}

void		cmd_def_rot_y(t_pars *pars, char **line)
{
	if (pars->last_type == LAST_OBJ)
		e->e_scene->scene->obj->rot_y = ft_atoi([0]);
	else if (parser->last_type == LAST_LIGHT)
		e->e_scene->scene->light->dir.y = ft_atoi([0]);
	else
		ft_printf("%s rot y", MSG_CMD_DEF);
}

void		cmd_def_rot_z(t_pars *pars, char **line)
{
	if (pars->last_type == LAST_OBJ)
		e->e_scene->scene->obj->rot_z = ft_atoi([0]);
	else if (parser->last_type == LAST_LIGHT)
		e->e_scene->scene->light->dir.z = ft_atoi([0]);
	else
		ft_printf("%s rot z", MSG_CMD_DEF);
}
