/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 14:45:45 by qstemper          #+#    #+#             */
/*   Updated: 2016/09/28 17:41:57 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	read_pos(t_env *e, int fd)
{
	char	*line;
	char	**split_line;
	int		i;

	i = 0;
	if (get_next_line(fd, &line) < 1)
		error_map();
	split_line = ft_strsplit(line, ' ');
	while (split_line[i] != '\0')
		i++;
	if (i != 4)
		error_map();
	e->map_width = ft_atoi(split_line[0]);
	e->map_height = ft_atoi(split_line[1]);
	e->player.pos.x= ft_atoi(split_line[2]) + 0.5;
	e->player.pos.y = ft_atoi(split_line[3]) + 0.5;
	if (e->map_width < 0 || e->map_height < 0 || e->player.pos.x < 0 || \
			e->player.pos.y < 0 || e->player.pos.x >= e->map_width || \
			e->player.pos.y >= e->map_width)
		error_map();
}

static void	read_line(char *line, int y, int **map, t_env *e)
{
	int		x;
	char	**split_line;

	x = -1;
	if (y >= e->map_height)
		error_map();
	split_line = ft_strsplit(line, ' ');
	if(!(map[y] = (int *)malloc(sizeof(int *) * e->width)))
		error_malloc();
	while (split_line[++x] != '\0')
	{
		if (!(split_line[x][0] >= '0' && split_line[x][0] <= '9' && \
					ft_atoi(split_line[x]) >= 0 && x < e->map_width))
			error_map();
		map[y][x] = ft_atoi(split_line[x]);
		if ((x == 0 || x == e->map_width - 1 || y == 0 || \
					y == e->map_height - 1) && map[y][x] == 0)
		error_map();
	}
	if (x != e->map_width)
		error_map();
}

static int	read_file(t_env *e, int fd)
{
	char	*line;
	int		y;
	int		**map;

	y = -1;
	read_pos(e, fd);
	if (!(map = (int **)malloc(sizeof(int **) * e->map_height)))
		error_malloc();
	while (get_next_line(fd, &line) == 1)
		read_line(line, ++y, map, e);
	if (map[(int)e->player.pos.x][(int)e->player.pos.y] != 0)
		error_map();
	e->map = map;
	return (1);
}

int			open_file(t_env *e, char *f)
{
	int		fd;

	if ((fd = open(f, O_DIRECTORY)) >= 0)
			return (0);
	if ((fd = open(f, O_RDONLY)) < 0)
		return (0);
	return (read_file(e, fd));
}
