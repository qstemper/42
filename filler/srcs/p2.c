/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p2.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 10:24:57 by qstemper          #+#    #+#             */
/*   Updated: 2017/04/14 10:57:55 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		check_column(t_info *info, int x)
{
	int		y;

	y = 0;
	while (y < info->heightmap)
	{
		if (info->map[y][x] == info->piece)
			return (1);
		y++;
	}
	return (0);
}

static int		check_line_bot(t_info *info, int y, char c)
{
	int		x;

	x = 0;
	while (x < info->weightmap)
	{
		if (info->map[y][x] == c || info->map[y][x] == ft_toupper(c))
			return (1);
		x++;
	}
	return (0);
}

static int		check_aggresive_bot(t_info *info)
{
	int		y;
	int		x;

	y = 0;
	while (y < info->heightmap)
	{
		x = 0;
		while (x < info->weightmap)
		{
			if (info->map[y][x] == info->piece)
			{
				if (check_line_bot(info, y, 'o') == 1)
					return (1);
				else
					return (0);
			}
			x++;
		}
		y++;
	}
	return (0);
}

static void		check_stop_aggresive_bot(t_info *info)
{
	int		x;

	x = 0;
	while (x < info->weightmap)
	{
		if (info->map[info->heightmap - 1][x] == info->piece)
		{
			info->stopaggresive = 1;
			return ;
		}
		x++;
	}
	info->stopaggresive = 0;
}

int				p2(t_info *info, t_piece *piece)
{
	info->cantplace = 0;
	get_map(info, piece);
	get_midmap(info);
	check_stop_aggresive_bot(info);
	if (check_column(info, info->weightmap - 1) == 0 &&
	check_column(info, 0) == 0 &&
	check_line_bot(info, info->midmap, 'x') == 1 &&
	check_aggresive_bot(info) == 0)
		place_right_p2(info, piece);
	else if (check_aggresive_bot(info) == 1 && info->stopaggresive == 0)
		place_bot_p2(info, piece);
	else
		place_top_p2(info, piece);
	if (info->cantplace == 1 || info->cantplacerl == 1)
		place_top_p2(info, piece);
	if (info->finish == 1)
	{
		ft_printf("0 0\n");
		return (0);
	}
	return (1);
}
