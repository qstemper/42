#include "filler.h"

static void	read_map_find_me(t_filler *fill)
{
	int i;
	int j;

	i = 0;
	while (i < fill->smap_y)
	{
		j = 0;
		while (j < fill->smap_x)
		{
			if (fill->map[i][j] == (char)(fill->pchar))
			{
				fill->me_y = i;
				fill->me_x = j;
			}
			j++;
		}
		i++;
	}
}

static void	read_map_find_vs(t_filler *fill)
{
	int		i;
	int		j;
	char	c;

	if ((char)(fill->pchar) == 'X')
		c = 'O';
	else
		c = 'X';
	i = 0;
	while (i < fill->smap_y)
	{
		j = 0;
		while (j < fill->smap_x)
		{
			if (fill->map[i][j] == c)
			{
				fill->vs_y = i;
				fill->vs_x = j;
			}
			j++;
		}
		i++;
	}
}

static void	read_map_debug(t_filler *fill, int choice, int i)
{
	if (O_DEBUG == 1 && choice == 1)
		ft_printf("SIZE MAP %d %d\n", fill->smap_y, fill->smap_x);
	if (O_DEBUG == 1 && choice == 2)
	{
		i = -1;
		ft_printf("  ");
		while (++i < fill->smap_x)
			ft_putnbr_fd(i % 10, fill->fd);
		ft_printf("\n");
	}
	if (O_DEBUG == 1 && choice == 3)
	{
		ft_putnbr_fd(i % 10, fill->fd);
		ft_printf(" ");
		ft_putstr_fd(fill->map[i], fill->fd);
		ft_printf("MAP\n");
	}
}

static void	map(t_filler *fill)
{
	int		i;
	int		ret;
	char	*line;
	char	*tmp;

	i = -1;
	while (++i < fill->smap_y)
	{
		if ((ret = get_next_line(0, &line)) != 1)
		{
			fill->exit = 1;
			return ;
		}
		tmp = fill->map[i];
		fill->map[i] = ft_strdup(line + (ft_strlen(line) - fill->smap_x));
		read_map_debug(fill, 3, i);
		ft_strdel(&line);
		ft_strdel(&tmp);
	}
	if (fill->me_x == -1)
	{
		read_map_find_me(fill);
		read_map_find_vs(fill);
	}
}

void		read_map(t_filler *fill)
{
	int		ret;
	int		i;
	char	**split;
	char	*line;
	
	i = 0;
	if ((ret = get_next_line(0, &line)) != 1)
		return ;
	if (fill->map == NULL)
	{
		split = ft_strsplit(line, ' ');
		fill->smap_y = ft_atoi(split[1]);
		fill->smap_x = ft_atoi(split[2]);
		ft_strsplit_free(&split);
		read_map_debug(fill, 1, i);
		if (!(fill->map = (char**)malloc(sizeof(fill->map) * \
				(fill->smap_y + 1))))
			filler_error(0);
		i = -1;
		while (++i <= fill->smap_y)
			fill->map[i] = NULL;
	}
	ret = get_next_line(0, &line);
	read_map_debug(fill, 2, i);
	map(fill);
}
