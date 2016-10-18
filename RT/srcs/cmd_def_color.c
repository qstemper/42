/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_def_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 16:37:18 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/18 16:50:39 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		cmd_def_color(t_pars *pars, char **line)
{
	if (pars->last_type == LAST_OBJ)
		e->e_scene->scene->obj->color.color = ft_atoi(line[0]);
	else 
		ft_printf("%s color", MSG_CMD_DEF);
}

void		cmd_def_red(t_pars *pars, char **line)
{
	if (parser->last_type == LAST_LIGHT)
		e->e_scene->scene->light->color.red = ft_atoi(line[0]);
	else
		ft_printf("%s color red", MSG_CMD_DEF);
}

void		cmd_def_green(t_pars *pars, char **line)
{
	if (parser->last_type == LAST_LIGHT)
		e->e_scene->scene->light->color.green = ft_atoi(line[0]);
	else
		ft_printf("%s color green", MSG_CMD_DEF);
}

void		cmd_def_red(t_pars *pars, char **line)
{
	if (parser->last_type == LAST_LIGHT)
		e->e_scene->scene->light->color.blue = ft_atoi(line[0]);
	else
		ft_printf("%s color blue", MSG_CMD_DEF);
}

