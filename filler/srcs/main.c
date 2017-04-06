/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 10:24:26 by qstemper          #+#    #+#             */
/*   Updated: 2017/04/06 13:16:38 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		init(t_info *info, t_piece *piece)
{
	info->numplayer = 0;
	info->midmap = 0;
	info->stopaggresive = 0;
	info->cantplace = 0;
	info->cantplacerl = 0;
	info->finish = 0;
	piece->heightpiece = 0;
	piece->weightpiece = 0;
}

int				main(void)
{
	t_info		info;
	t_piece		piece;

	init(&info, &piece);
	get_player(&info);
	assign_piece(&info);
	get_map_size(&info);
	while (1)
	{
		if (info.numplayer == 1)
		{
			if (p1(&info, &piece) == 0)
				break ;
		}
		else if (info.numplayer == 2)
		{
			if (p2(&info, &piece) == 0)
				break ;
		}
	}
	return (0);
}
