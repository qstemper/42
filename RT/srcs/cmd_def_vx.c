/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_def_vx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 16:17:23 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/18 16:31:15 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	cmd_def_vx_x(t_pars *pars, char **line)
{
	if (pars->last_type == LAST_CAM)
			e->e_scene->cam.vx.x = (float)ft_atoi(line[0]);
	else
		ft_printf("%s vx_x", MSG_CMD_DEF);
}

void	cmd_def_vx_y(t_pars *pars, char **line)
{
	if (pars->last_type == LAST_CAM)
			e->e_scene->cam.vx.y = (float)ft_atoi(line[0]);
	else
		ft_printf("%s vx_y", MSG_CMD_DEF);
}

void	cmd_def_vx_z(t_pars *pars, char **line)
{
	if (pars->last_type == LAST_CAM)
			e->e_scene->cam.vx.z = (float)ft_atoi(line[0]);
	else
		ft_printf("%s vx_z", MSG_CMD_DEF);
}
