/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_def2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 17:04:21 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/18 18:42:31 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		cmd_def_opacity(t_pars *pars, char **line)
{
	if (pars->last_type == LAST_OBJ)
		e->e_scene->scene->obj->opacity = ft_atoi(line[0]);
	else 
		ft_printf("%s opacity", MSG_CMD_DEF);
}

void		cmd_def_radius(t_pars *pars, char **line)
{
	if (pars->last_type == LAST_OBJ)
	{
		if (e->e_scene->scene->obj->type == OBJ_CONE || \
				e->e_scene->scene->obj->type == OBJ_SPHERE || \
				e->e_scene->scene->obj->type == OBJ_CYL)	
			e->e_scene->scene->obj->radius = ft_atoi(line[0]);
	}
	else
		ft_printf("%s radius", MSG_CMD_DEF);
}

void		cmd_def_recurs(t_pars *pars, char **line)
{
	int		recurs;

	if (parser->last_type == LAST_NONE)
	{
		recurs = ft_atoi(line[0]);
		if (recurs >= 0 && recurs <= 1000)
			e->e_scene->scene->recurs = recurs;
	}
	else
		ft_printf("%s recurs", MSG_CMD_DEF);
}

void		cmd_def_mirror(t_pars *pars, char **line)
{
	if (pars->last_type == LAST_OBJ)
		e->e_scene->scene->obj->mirror = ft_atoi(line[0]);
	else 
		ft_printf("%s mirror", MSG_CMD_DEF);
}
