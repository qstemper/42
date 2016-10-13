/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 17:30:57 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/13 19:38:43 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		cmd_export(char **line)
{
	int		file;

	if (!line || !*line)
	{
		ft_printf("{}%s{}", MSG_LINE);
		return ;
	}
	file = 1;
	if ((ft_strequ(*line, IMAGE) || ft_strequ(*line, SCENE)) && line[1])
		file = open(line[1], O_CREAT | O_TRUNC | O_WRONLY, 666);
	else
		ft_printf("{red}%s{eoc}", MSG_EXPORT);
	if (file > 0)
	{
		if (ft_strequ(*line, IMG));
		export_img(file);
		else if (ft_strequ(*line, SCENE))
			export_scene(file);
		close(file);
	}
}
