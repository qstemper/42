/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fil_readmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclerc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 17:31:41 by jclerc            #+#    #+#             */
/*   Updated: 2016/10/02 20:11:31 by jclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	fil_readmap_find_me(t_filler *main)
{
	int i;
	int j;

	i = 0;
	while (i < main->smap_y)
	{
		j = 0;
		while (j < main->smap_x)
		{
			if (main->map[i][j] == (char)(main->pchar))
			{
				main->me_y = i;
				main->me_x = j;
			}
			j++;
		}
		i++;
	}
}

static void	fil_readmap_find_vs(t_filler *main)
{
	int		i;
	int		j;
	char	c;

	if ((char)(main->pchar) == 'X')
		c = 'O';
	else
		c = 'X';
	i = 0;
	while (i < main->smap_y)
	{
		j = 0;
		while (j < main->smap_x)
		{
			if (main->map[i][j] == c)
			{
				main->vs_y = i;
				main->vs_x = j;
			}
			j++;
		}
		i++;
	}
}

static void	fil_readmap_debug(t_filler *main, int choice, int i)
{
	if (DEBUG == 1 && choice == 1)
	{
		ft_putstr_fd("SIZE MAP ", main->fd);
		ft_putnbr_fd(main->smap_y, main->fd);
		ft_putstr_fd(" ", main->fd);
		ft_putnbr_fd(main->smap_x, main->fd);
		ft_putstr_fd("\n", main->fd);
	}
	if (DEBUG == 1 && choice == 2)
	{
		i = -1;
		ft_putstr_fd("  ", main->fd);
		while (++i < main->smap_x)
			ft_putnbr_fd(i % 10, main->fd);
		ft_putstr_fd("\n", main->fd);
	}
	if (DEBUG == 1 && choice == 3)
	{
		ft_putnbr_fd(i % 10, main->fd);
		ft_putstr_fd(" ", main->fd);
		ft_putstr_fd(main->map[i], main->fd);
		ft_putstr_fd("MAP\n", main->fd);
	}
}

static void	fil_readmap_map(t_filler *main)
{
	int		i;
	int		ret;
	char	*line;
	char	*tmp;

	i = -1;
	while (++i < main->smap_y)
	{
		if ((ret = get_next_line(0, &line)) != 1)
		{
			main->exit = 1;
			return ;
		}
		tmp = main->map[i];
		main->map[i] = ft_strdup(line + (ft_strlen(line) - main->smap_x));
		fil_readmap_debug(main, 3, i);
		ft_strdel(&line);
		ft_strdel(&tmp);
	}
	if (main->me_x == -1)
	{
		fil_readmap_find_me(main);
		fil_readmap_find_vs(main);
	}
}

void		fil_readmap(t_filler *main)
{
	int		ret;
	int		i;
	char	**split;
	char	*line;
	
	i = 0;
	if ((ret = get_next_line(0, &line)) != 1)
		return ;
	if (main->map == NULL)
	{
		split = ft_strsplit(line, ' ');
		main->smap_y = ft_atoi(split[1]);
		main->smap_x = ft_atoi(split[2]);
		ft_strsplit_free(&split);
		fil_readmap_debug(main, 1, i);
		main->map = (char**)malloc(sizeof(main->map) * (main->smap_y + 1));
		i = -1;
		while (++i <= main->smap_y)
			main->map[i] = NULL;
	}
	ret = get_next_line(0, &line);
	fil_readmap_debug(main, 2, i);
	fil_readmap_map(main);
}
