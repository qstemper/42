/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_recurs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 20:10:39 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/13 20:23:29 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			cmd_recurs(char **line)
{
	int			val;

	val = -1;
	if (!line || !*line)
	{
		ft_printf("{red}%s{eoc}\n", MSG_LINE);
		return ;
	}
	val = ft_atoi(*line);
	if (val < 0 || val > 40 || !line[1])
		env->e_scene.scene.recurs = (unsigned int)val;
	else
		ft_printf("{grey}%s{eoc}\nYour value : %d\n", \
				USE_REC, env->e_scene.scene.recurs);
}
