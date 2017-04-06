/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_p1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 10:25:09 by qstemper          #+#    #+#             */
/*   Updated: 2017/04/06 11:18:18 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	take_piece_right(t_info *info, t_piece *piece, int y, int x)
{
	int		i;
	int		j;

	i = piece->heightpiece - 1;
	while (i >= 0)
	{
		j = piece->weightpiece - 1;
		while (j >= 0)
		{
			if (piece->piece[i][j] == '*')
			{
				if (check_place(info, piece, x - j, y - i))
				{
					ft_printf("%d %d\n", y - i, x - j);
					return (1);
				}
			}
			j--;
		}
		i--;
	}
	return (0);
}

static int	take_piece_left(t_info *info, t_piece *piece, int y, int x)
{
	int		i;
	int		j;

	i = 0;
	while (i < piece->heightpiece)
	{
		j = 0;
		while (j < piece->weightpiece)
		{
			if (piece->piece[i][j] == '*')
			{
				if (check_place(info, piece, x - j, y - i))
				{
					ft_printf("%d %d\n", y - i, x - j);
					return (1);
				}
			}
			j++;
		}
		i++;
	}
	return (0);
}

void		place_top_p1(t_info *info, t_piece *piece)
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
				if (take_piece_right(info, piece, y, x) == 1)
					return ;
			}
			x++;
		}
		y++;
	}
	info->cantplace = 1;
}

void		place_bot_p1(t_info *info, t_piece *piece)
{
	int		y;
	int		x;

	y = info->heightmap - 1;
	while (y > 0)
	{
		x = info->weightmap - 1;
		while (x > 0)
		{
			if (info->map[y][x] == info->piece)
			{
				if (take_piece_left(info, piece, y, x) == 1)
					return ;
			}
			x--;
		}
		y--;
	}
	info->finish = 1;
}

void		place_left_p1(t_info *info, t_piece *piece)
{
	int		y;
	int		x;

	y = info->midmap + (info->heightmap / 10) - (info->heightmap / 11);
	while (y < info->midmap + (info->heightmap / 10) + (info->heightmap / 11))
	{
		x = 0;
		while (x < info->weightmap)
		{
			if (info->map[y][x] == info->piece)
			{
				if (take_piece_right(info, piece, y, x) == 1)
					return ;
			}
			x++;
		}
		y++;
	}
	info->cantplacerl = 1;
}
