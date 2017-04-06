/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 10:24:13 by qstemper          #+#    #+#             */
/*   Updated: 2017/04/06 11:53:30 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			get_player(t_info *info)
{
	char		*line;

	get_next_line(0, &line);
	info->numplayer = ft_atoi(&line[10]);
}

void			assign_piece(t_info *info)
{
	if (info->numplayer == 1)
		info->piece = 'O';
	else
		info->piece = 'X';
}

void			get_map_size(t_info *info)
{
	char		*line;

	get_next_line(0, &line);
	info->heightmap = ft_atoi(&line[8]);
	info->weightmap = ft_atoi(&line[11]);
}


