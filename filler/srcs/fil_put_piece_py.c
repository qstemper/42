/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fil_put_piece_check.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclerc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 19:08:30 by jclerc            #+#    #+#             */
/*   Updated: 2016/10/02 18:29:21 by jclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	fil_put_piece_hbgd_py(t_filler *main, int y, int x)
{
	int i;
	int j;

	j = x;
	while (j < main->smap_x)
	{
		main->put_x = j;
		i = y;
		while (i < main->smap_y)
		{
			main->put_y = i;
			if (fil_put_piece_check(main))
				return ;
			i++;
		}
		j++;
	}
	main->put_y = -1;
	main->put_x = -1;
}

void	fil_put_piece_hbdg_py(t_filler *main, int y, int x)
{
	int i;
	int j;

	j = x;
	while (j >= 1 - main->spiece_x)
	{
		main->put_x = j;
		i = y;
		while (i < main->smap_y)
		{
			main->put_y = i;
			if (fil_put_piece_check(main))
				return ;
			i++;
		}
		j--;
	}
	main->put_y = -1;
	main->put_x = -1;
}

void	fil_put_piece_bhdg_py(t_filler *main, int y, int x)
{
	int i;
	int j;

	j = x;
	while (j >= 1 - main->spiece_x)
	{
		main->put_x = j;
		i = y;
		while (i >= 1 - main->spiece_y)
		{
			main->put_y = i;
			if (fil_put_piece_check(main))
				return ;
			i--;
		}
		j--;
	}
	main->put_y = -1;
	main->put_x = -1;
}

void	fil_put_piece_bhgd_py(t_filler *main, int y, int x)
{
	int i;
	int j;

	j = x;
	while (j < main->smap_x)
	{
		main->put_x = j;
		i = y;
		while (i >= 1 - main->spiece_y)
		{
			main->put_y = i;
			if (fil_put_piece_check(main))
				return ;
			i--;
		}
		j++;
	}
	main->put_y = -1;
	main->put_x = -1;
}
