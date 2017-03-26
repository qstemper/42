/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fil_put_piece_check.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclerc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 19:08:30 by jclerc            #+#    #+#             */
/*   Updated: 2016/10/02 18:26:26 by jclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	fil_put_piece_check_bis(t_filler *main, int i, int j, int *nb)
{
	int y;
	int x;

	x = main->put_x;
	y = main->put_y;
	while (j < main->spiece_x)
	{
		if (main->piece[i][j] == '*' && (y + i < 0 || x + j < 0
					|| y + i >= main->smap_y || x + j >= main->smap_x))
			return (0);
		else if (main->piece[i][j] == '*'
				&& main->map[y + i][x + j] == main->pchar)
			(*nb)++;
		else if (main->piece[i][j] == '*'
				&& main->map[y + i][x + j] == main->lpchar)
			(*nb)++;
		else if (main->piece[i][j] == '*' && main->map[y + i][x + j] != '.')
			return (0);
		if (*nb > 1)
			return (0);
		j++;
	}
	return (1);
}

int			fil_put_piece_check(t_filler *main)
{
	int i;
	int j;
	int nb;
	int ret;

	nb = 0;
	ret = 0;
	i = 0;
	while (i < main->spiece_y)
	{
		j = 0;
		ret = fil_put_piece_check_bis(main, i, j, &nb);
		if (ret == 0)
			return (0);
		i++;
	}
	if (nb != 1)
		return (0);
	return (ret);
}
