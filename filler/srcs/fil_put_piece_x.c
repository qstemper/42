/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fil_put_piece_check.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclerc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 19:08:30 by jclerc            #+#    #+#             */
/*   Updated: 2016/10/02 19:09:28 by jclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	fil_put_piece_bhgd(t_filler *main)
{
	int i;
	int j;

	i = main->smap_y - 1;
	while (i >= 1 - main->spiece_y)
	{
		main->put_y = i;
		j = 1 - main->spiece_x;
		while (j < main->smap_x)
		{
			main->put_x = j;
			if (fil_put_piece_check(main))
				return ;
			j++;
		}
		i--;
	}
	main->put_y = -1;
	main->put_x = -1;
}

void	fil_put_piece_bhdg(t_filler *main)
{
	int i;
	int j;

	i = main->smap_y - 1;
	while (i >= 1 - main->spiece_y)
	{
		main->put_y = i;
		j = main->smap_x - 1;
		while (j >= 1 - main->spiece_x)
		{
			main->put_x = j;
			if (fil_put_piece_check(main))
				return ;
			j--;
		}
		i--;
	}
	main->put_y = -1;
	main->put_x = -1;
}

void	fil_put_piece_hbdg(t_filler *main)
{
	int i;
	int j;

	i = 1 - main->spiece_y;
	while (i < main->smap_y)
	{
		main->put_y = i;
		j = main->smap_x - 1;
		while (j >= 1 - main->spiece_x)
		{
			main->put_x = j;
			if (fil_put_piece_check(main))
				return ;
			j--;
		}
		i++;
	}
	main->put_y = -1;
	main->put_x = -1;
}

void	fil_put_piece_hbgd(t_filler *main)
{
	int i;
	int j;

	i = 1 - main->spiece_y;
	while (i < main->smap_y)
	{
		main->put_y = i;
		j = 1 - main->spiece_x;
		while (j < main->smap_x)
		{
			main->put_x = j;
			if (fil_put_piece_check(main))
				return ;
			j++;
		}
		i++;
	}
	main->put_y = -1;
	main->put_x = -1;
}
