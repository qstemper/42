/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_if_name.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 16:47:03 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/13 20:23:15 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		cmd_if_name(char **line)
{
	int		val;

	val = -1;
	if (!line || !*line)
	{
		ft_printf("{red}%s{eoc}\n", MSG_LINE);
		return ;
	}
	value = ft_atoi(*line);
	if (val < 1 || val > 40 || !line[1])
		env->e_scene->scene->antialias = (unsigned int)val;
	else
		ft_printf("{grey}%s{eoc}\nYour value : %d\n", \
				USE_ALIAS, env->e_scene.scene.antialias);
}
