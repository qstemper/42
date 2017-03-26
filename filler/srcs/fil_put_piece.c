/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fil_put_piece_check.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclerc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 19:08:30 by jclerc            #+#    #+#             */
/*   Updated: 2016/10/02 20:11:48 by jclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		fil_put_find_me(t_filler *main, int y, float vs, float me)
{
	int		tab[5];
	char	c;

	tab[0] = y;
	tab[1] = 0;
	tab[2] = 0;
	tab[3] = 0;
	tab[4] = 0;
	c = (main->pchar == 'O') ? 'X' : 'O';
	while (tab[1] < main->smap_x)
	{
		if (main->map[tab[0]][tab[1]] == c)
			tab[2]++;
		if (main->map[tab[0]][tab[1]] == (char)(main->lpchar)
				|| main->map[tab[0]][tab[1]] == (char)(main->pchar))
			tab[3]++;
		if (main->map[tab[0]][tab[1]] != '.')
			tab[4]++;
		tab[1]++;
	}
	if (tab[2] > (int)((float)main->smap_x * vs)
			|| tab[3] > (int)((float)main->smap_x * me)
			|| tab[4] >= main->smap_x - 1)
		return (1);
	return (0);
}

void	fil_put_piece(t_filler *main)
{
	int mid_x;
	int mid_y;

	mid_x = (int)(main->smap_x / 2);
	mid_y = (int)(main->smap_y / 2);
	if (DEBUG == 1)
	{
		ft_putstr_fd("MID MAP ", main->fd);
		ft_putnbr_fd(mid_y, main->fd);
		ft_putstr_fd(" ", main->fd);
		ft_putnbr_fd(mid_x, main->fd);
		ft_putstr_fd("\n", main->fd);
	}
	fil_put_piece_haut_a(main, mid_x, mid_y);
	fil_put_piece_haut_b(main, mid_x, mid_y);
	fil_put_piece_haut_c(main, mid_x, mid_y);
	fil_put_piece_haut_d(main, mid_x, mid_y);
	fil_put_piece_haut_e(main, mid_x, mid_y);
	fil_put_piece_bas_a(main, mid_x, mid_y);
	fil_put_piece_bas_b(main, mid_x, mid_y);
	fil_put_piece_bas_c(main, mid_x, mid_y);
	fil_put_piece_bas_d(main, mid_x, mid_y);
}
