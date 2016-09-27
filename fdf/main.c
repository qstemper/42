/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 22:46:51 by qstemper          #+#    #+#             */
/*   Updated: 2016/09/27 02:43:52 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	usable_key(void)
{
	ft_putendl("Here is the key you can use in FdF :");
	ft_putendl("\tESC & Q to quit the progam");
	ft_putendl("\tPlus & Minus to zoom or dezoom");
	ft_putendl("\tUp & Down Arrows to change the value of z");
	ft_putendl("\tR to reinitialize the map");
}

int			main(int ac, char **av)
{
	int		fmlx;
	int		x;
	int		y;
	t_list	*listpoint;
	t_list	tmp;

	listpoint = NULL;
	x = 0;
	y = 0;
	if (ac != 2)
		return (-1);
	usable_key();
	if (fdf(av[1], &listpoint, &x, &y) == 0)
		return (-1);
	tmp = *listpoint;
	if (!(fmlx = fdf_mlx(&listpoint, av[1], x, y)))
		return (-1);
	return (0);
}
