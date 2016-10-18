/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_def1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 14:08:27 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/18 18:08:24 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		cmd_def_ambient(t_pars *pars, char **line)
{
	if (pars->last_type == LAST_OBJ)
		e->e_scene->scene->obj->ambient = ft_atoi(line[0]);
	else 
		ft_printf("%s ambient", MSG_CMD_DEF);
}

void		cmd_def_if_name(t_pars *pars, char **line)
{
	int		if_name;

	if (pars->last_type == LAST_NONE)
	{
		if_name = ft_atoi(line[0]);
		if (if_name >= 1 && if_name <= 40)
			e->e_escene->scene->if_name = if_name;
	}
	else
		ft_printf("%s if_name", MSG_CMD_DEF);
}

void		cmd_def_diaph(t_pars *pars, char **line)
{
	if (pars->last_type == LAST_NONE)
		e->e_scene->scene->diaph = ft_atoi(line[0]);
	else 
		ft_printf("%s diaph", MSG_CMD_DEF);
}

void		cmd_def_diffuse(t_pars *pars, char **line)
{
	if (pars->last_type == LAST_OBJ)
		e->e_scene->scene->obj->diffuse = ft_atoi(line[0]);
	else 
		ft_printf("%s diffuse", MSG_CMD_DEF);
}

void		cmd_def_intens(t_pars *pars, char **line)
{
	if (pars->last_type == LAST_LIGHT)
		e->e_scene->scene->obj->intens = ft_atoi(line[0]);
	else 
		ft_printf("%s intens", MSG_CMD_DEF);
}
