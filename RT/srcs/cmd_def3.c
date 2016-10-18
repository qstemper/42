/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_def3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 17:45:30 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/18 18:06:23 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		cmd_def_height(t_pars *pars, char **line)
{
	if (pars->last_type == LAST_NONE)
		e->e_scene->scene->height = ft_atoi(line[0]);
	else 
		ft_printf("%s height", MSG_CMD_DEF);
}

void		cmd_def_width(t_pars *pars, char **line)
{
	if (pars->last_type == LAST_NONE)
		e->e_scene->scene->width = ft_atoi(line[0]);
	else 
		ft_printf("%s width", MSG_CMD_DEF);
}

void		cmd_def_reflec(t_pars *pars, char **line)
{
	if (pars->last_type == LAST_OBJ)
		e->e_scene->scene->obj->reflec = ft_atoi(line[0]);
	else 
		ft_printf("%s reflec", MSG_CMD_DEF);
}

void		cmd_def_refrac(t_pars *pars, char **line)
{
	if (pars->last_type == LAST_OBJ)
		e->e_scene->scene->obj->refrac = ft_atoi(line[0]);
	else 
		ft_printf("%s refrac", MSG_CMD_DEF);
}
