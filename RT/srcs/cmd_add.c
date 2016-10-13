/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 08:08:07 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/13 16:36:50 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	cmd_add(char **line)
{
	if (*line && !line[1])
	{
		if (ft_strequ(SPHERE, *line))
			add_sphere();
		else if (ft_strequ(CONE, *line))
			add_cone();
		else if (ft_strequ(CYL, *line))
			add_cyl();
		else if (ft_strequ(PLANE, *line))
			add_plane();
		else if (ft_strequ(LIGHT, *line))
			add_light();
		else
			ft_printf("{red}%s{eoc}", OBJ_ERROR);
	}
	else
		ft_printf("{cyan}%s{eoc}", OBJ_USE);
}
