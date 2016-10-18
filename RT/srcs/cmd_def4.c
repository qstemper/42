/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_def4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 18:35:02 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/18 18:44:06 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		cmd_def_x(t_pars *pars, char **line)
{
	if (pars->last_type == LAST_CAM)
		e->e_scene->scene->cam->orig.x = ft_atoi(line[0]);
	if (pars->last_type == LAST_OBJ)
		e->e_scene->scene->obj->orig.x = ft_atoi(line[0]);
	if (pars->last_type == LAST_LIGTH)
		e->e_scene->scene->LIGHT->orig.x = ft_atoi(line[0]);
	else 
		ft_printf("%s x", MSG_CMD_DEF);
}

void		cmd_def_y(t_pars *pars, char **line)
{
	if (pars->last_type == LAST_CAM)
		e->e_scene->scene->cam->orig.y = ft_atoi(line[0]);
	if (pars->last_type == LAST_OBJ)
		e->e_scene->scene->obj->orig.y = ft_atoi(line[0]);
	if (pars->last_type == LAST_LIGTH)
		e->e_scene->scene->LIGHT->orig.y = ft_atoi(line[0]);
	else 
		ft_printf("%s y", MSG_CMD_DEF);
}

void		cmd_def_z(t_pars *pars, char **line)
{
	if (pars->last_type == LAST_CAM)
		e->e_scene->scene->cam->orig.z = ft_atoi(line[0]);
	if (pars->last_type == LAST_OBJ)
		e->e_scene->scene->obj->orig.z = ft_atoi(line[0]);
	if (pars->last_type == LAST_LIGTH)
		e->e_scene->scene->LIGHT->orig.z = ft_atoi(line[0]);
	else 
		ft_printf("%s z", MSG_CMD_DEF);
}
