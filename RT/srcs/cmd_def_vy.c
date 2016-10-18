/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_def_vy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 16:22:45 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/18 16:30:42 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	cmd_def_vy_x(t_pars *pars, char **line)
{
	if (pars->last_type == LAST_CAM)
			e->e_scene->cam.vy.x = (float)ft_atoi(line[0]);
	else
		ft_printf("%s vy_x", MSG_CMD_DEF);
}

void	cmd_def_vy_y(t_pars *pars, char **line)
{
	if (pars->last_type == LAST_CAM)
			e->e_scene->cam.vy.y = (float)ft_atoi(line[0]);
	else
		ft_printf("%s vy_y", MSG_CMD_DEF);
}

void	cmd_def_vy_z(t_pars *pars, char **line)
{
	if (pars->last_type == LAST_CAM)
			e->e_scene->cam.vy.z = (float)ft_atoi(line[0]);
	else
		ft_printf("%s vy_z", MSG_CMD_DEF);
}
