/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_def_vz.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 16:31:05 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/18 17:03:01 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	cmd_def_vz_x(t_pars *pars, char **line)
{
	if (pars->last_type == LAST_CAM)
			e->e_scene->cam.vz.x = (float)ft_atoi(line[0]);
	else
		ft_printf("%s vz_x", MSG_CMD_DEF);
}

void	cmd_def_vz_y(t_pars *pars, char **line)
{
	if (pars->last_type == LAST_CAM)
			e->e_scene->cam.vz.y = (float)ft_atoi(line[0]);
	else
		ft_printf("%s vz_y", MSG_CMD_DEF);
}

void	cmd_def_vz_z(t_pars *pars, char **line)
{
	if (pars->last_type == LAST_CAM)
			e->e_scene->cam.vz.z = (float)ft_atoi(line[0]);
	else
		ft_printf("%s vz_z", MSG_CMD_DEF);
}
