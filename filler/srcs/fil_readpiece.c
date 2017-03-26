/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fil_initvm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclerc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 16:54:44 by jclerc            #+#    #+#             */
/*   Updated: 2016/10/02 18:50:23 by jclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	fil_readpiece_free(t_filler *main)
{
	int i;

	if (main->piece == NULL)
		return ;
	i = 0;
	while (i <= main->spiece_y)
	{
		ft_strdel(&main->piece[i]);
		i++;
	}
	free(main->piece);
	main->piece = NULL;
}

static void	fil_readpiece_debug(t_filler *main, int choice, int i)
{
	if (DEBUG == 1 && choice == 1)
	{
		ft_putstr_fd("SIZE PIECE ", main->fd);
		ft_putnbr_fd(main->spiece_y, main->fd);
		ft_putstr_fd(" ", main->fd);
		ft_putnbr_fd(main->spiece_x, main->fd);
		ft_putstr_fd("\n", main->fd);
	}
	if (DEBUG == 1 && choice == 2)
	{
		ft_putstr_fd(main->piece[i], main->fd);
		ft_putstr_fd("PIECE\n", main->fd);
	}
}

static void	fil_readpiece_put(t_filler *main)
{
	int		i;
	int		ret;
	char	*line;

	i = 0;
	while (i < main->spiece_y)
	{
		errno = 0;
		if ((ret = get_next_line(0, &line)) != 1)
		{
			main->exit = 1;
			return ;
		}
		main->piece[i] = ft_strdup(line);
		fil_readpiece_debug(main, 2, i);
		ft_strdel(&line);
		ft_error(PRGM);
		i++;
	}
}

void		fil_readpiece(t_filler *main)
{
	int		ret;
	int		i;
	char	**split;
	char	*line;

	i = 0;
	fil_readpiece_free(main);
	if ((ret = get_next_line(0, &line)) != 1)
	{
		main->exit = 1;
		return ;
	}
	split = ft_strsplit(line, ' ');
	main->spiece_y = ft_atoi(split[1]);
	main->spiece_x = ft_atoi(split[2]);
	ft_strsplit_free(&split);
	fil_readpiece_debug(main, 1, i);
	main->piece = (char**)malloc(sizeof(main->piece) * (main->spiece_y + 1));
	while (i <= main->spiece_y)
		main->piece[i++] = NULL;
	fil_readpiece_put(main);
}
