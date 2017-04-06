/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_and_piece.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 10:24:35 by qstemper          #+#    #+#             */
/*   Updated: 2017/04/06 11:53:59 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		get_piece(t_piece *piece)
{
	char	*line;
	char	*piecejoin;
	int		i;
	int		nblinepiece;

	i = 0;
	piecejoin = "\0";
	nblinepiece = 0;
	get_next_line(0, &line);
	while (ft_isdigit(line[i]) == 0)
		i++;
	piece->heightpiece = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]) == 1)
		i++;
	i++;
	piece->weightpiece = ft_atoi(&line[i]);
	while (get_next_line(0, &line) > 0)
	{
		piecejoin = ft_strjoin(piecejoin, line);
		piecejoin = ft_strjoin(piecejoin, "\n");
		nblinepiece++;
		if (nblinepiece == piece->heightpiece)
			break ;
	}
	piece->piece = ft_strsplit(piecejoin, '\n');
}

void		get_midmap(t_info *info)
{
	int		midmap;
	int		j;

	j = 0;
	midmap = (info->heightmap / 2) - (info->heightmap / 10);
	while (info->map[midmap][j] != '\0')
	{
		if (info->map[midmap][j] == 'X')
			info->midmap = midmap;
		j++;
	}
}

void		get_map(t_info *info, t_piece *piece)
{
	char	*line;
	char	*mapjoin;
	int		nbline;

	mapjoin = "\0";
	nbline = 0;
	while (get_next_line(0, &line) > 0)
	{
		if (ft_isdigit(line[0]) == 1)
		{
			mapjoin = ft_strjoin(mapjoin, &line[4]);
			mapjoin = ft_strjoin(mapjoin, "\n");
			nbline++;
		}
		if (nbline == info->heightmap)
			break ;
	}
	info->map = ft_strsplit(mapjoin, '\n');
	get_piece(piece);
}
