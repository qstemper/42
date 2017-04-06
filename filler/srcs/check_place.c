/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_place.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 10:23:45 by qstemper          #+#    #+#             */
/*   Updated: 2017/04/06 11:53:25 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	check_place_bis(t_info *info, t_piece *piece, int x, int y)
{
	if (x > info->weightmap || x < 0)
		return (0);
	if (y > info->heightmap || y < 0)
		return (0);
	if (x + piece->weightpiece > info->weightmap)
		return (0);
	if (y + piece->heightpiece > info->heightmap)
		return (0);
	return (1);
}

static int	check_superpose(t_info *info, t_piece *piece, int x, int y)
{
	int		i;
	int		j;
	int		tmp;
	int		cpt;

	i = -1;
	tmp = x;
	cpt = 0;
	while (++i < piece->heightpiece)
	{
		j = -1;
		x = tmp;
		while (++j < piece->weightpiece)
		{
			if (info->numplayer == 1)
				if (piece->piece[i][j] == '*' && info->map[y][x] == 'O')
					cpt++;
			if (info->numplayer == 2)
				if (piece->piece[i][j] == '*' && info->map[y][x] == 'X')
					cpt++;
			x++;
		}
		y++;
	}
	return ((cpt > 1) ? 0 : 1);
}

static int	check_superpose_adverse(t_info *info, t_piece *piece, int x, int y)
{
	int		i;
	int		j;
	int		tmp;

	i = 0;
	tmp = x;
	while (i < piece->heightpiece)
	{
		j = 0;
		x = tmp;
		while (j < piece->weightpiece)
		{
			if (info->numplayer == 1)
				if (piece->piece[i][j] == '*' && info->map[y][x] == 'X')
					return (0);
			if (info->numplayer == 2)
				if (piece->piece[i][j] == '*' && info->map[y][x] == 'O')
					return (0);
			j++;
			x++;
		}
		i++;
		y++;
	}
	return (1);
}

int			check_place(t_info *info, t_piece *piece, int x, int y)
{
	if (check_place_bis(info, piece, x, y) == 0)
		return (0);
	if (check_superpose(info, piece, x, y) == 0)
		return (0);
	if (check_superpose_adverse(info, piece, x, y) == 0)
		return (0);
	return (1);
}
