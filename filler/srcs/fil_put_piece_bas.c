/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fil_put_piece_bas.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclerc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 19:27:47 by jclerc            #+#    #+#             */
/*   Updated: 2016/10/02 19:55:40 by jclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	fil_put_piece_bas_a_bis(t_filler *main, int mid_x, int mid_y)
{
	if (main->me_y >= mid_y && main->me_x >= mid_x
			&& main->vs_y <= mid_y && main->vs_x >= mid_x)
	{
		//OK me en bas a droite et vs en haut a droite
		if ((main->put_y == -1 && main->put_x == -1
					&& !fil_put_find_me(main, main->smap_y - 1, 0.7, 0.5)))
			fil_put_piece_bhgd(main);
		if (main->put_y == -1 && main->put_x == -1)
			fil_put_piece_hbgd(main);
	}
}

void		fil_put_piece_bas_a(t_filler *main, int mid_x, int mid_y)
{
	if (main->me_y >= mid_y && main->me_x >= mid_x && main->vs_y <= mid_y
			&& main->vs_x <= mid_x)
	{
		//OK me en bas a droite et vs en haut a gauche
		if (main->put_y == -1 && main->put_x == -1
				&& !fil_put_find_me(main, 0, 0.1, 0.05))
			fil_put_piece_hbgd(main);
		if ((main->put_y == -1 && main->put_x == -1
					&& !fil_put_find_me(main, main->smap_y - 1, 0.7, 0.5)))
			fil_put_piece_bhdg(main);
		if (main->put_y == -1 && main->put_x == -1
				&& !fil_put_find_me(main, 0, 0.6, 0.1))
			fil_put_piece_hbgd_y(main);
		if (main->mod % 2 == 0 && main->put_y == -1 && main->put_x == -1)
			fil_put_piece_hbdg_px(main, 1 - main->spiece_y, mid_x);
		if (main->mod % 5 == 0 && main->put_y == -1 && main->put_x == -1)
			fil_put_piece_hbdg_y(main);
		if (main->put_y == -1 && main->put_x == -1)
			fil_put_piece_bhgd_y(main);
	}
	fil_put_piece_bas_a_bis(main, mid_x, mid_y);
}

void		fil_put_piece_bas_b(t_filler *main, int mid_x, int mid_y)
{
	if (main->me_y >= mid_y && main->me_x >= mid_x && main->vs_y >= mid_y)
	{
		//OK me en bas a droite et vs en bas a gauche
		// me en bas a droite et vs en bas a droite
		if (main->put_y == -1 && main->put_x == -1
				&& !fil_put_find_me(main, 0, 0.1, 0.05))
			fil_put_piece_hbgd(main);
		if ((main->put_y == -1 && main->put_x == -1
					&& !fil_put_find_me(main, main->smap_y - 1, 0.7, 0.5)))
			fil_put_piece_bhdg(main);
		if (main->put_y == -1 && main->put_x == -1
				&& !fil_put_find_me(main, 0, 0.6, 0.1))
			fil_put_piece_hbgd_y(main);
		if (main->mod % 2 == 0 && main->put_y == -1 && main->put_x == -1)
			fil_put_piece_hbdg_px(main, 1 - main->spiece_y, mid_x);
		if (main->mod % 5 == 0 && main->put_y == -1 && main->put_x == -1)
			fil_put_piece_hbdg_y(main);
		if (main->put_y == -1 && main->put_x == -1)
			fil_put_piece_bhgd_y(main);
	}
}

void		fil_put_piece_bas_c(t_filler *main, int mid_x, int mid_y)
{
	if (main->me_y >= mid_y && main->me_x <= mid_x && main->vs_y >= mid_y)
	{
		//OK me en bas a gauche et vs en bas a droite
		// me en bas a gauche et vs en bas a gauche
		if ((main->mod % 2 == 0 && main->put_y == -1 && main->put_x == -1
					&& !fil_put_find_me(main, 0, 1.0, 0.05)))
			fil_put_piece_hbdg_y(main);
		if ((main->put_y == -1 && main->put_x == -1
					&& !fil_put_find_me(main, 0, 1.0, 0.05)))
			fil_put_piece_hbdg(main);
		if ((main->put_y == -1 && main->put_x == -1
					&& !fil_put_find_me(main, main->smap_y - 1, 1.0, 0.05)))
			fil_put_piece_bhgd(main);
		if ((main->put_y == -1 && main->put_x == -1
					&& !fil_put_find_me(main, mid_y - 1, 0.8, 0.6)))
			fil_put_piece_hbdg_py(main, mid_y - 1, main->smap_x - 1);
		if ((main->put_y == -1 && main->put_x == -1
					&& !fil_put_find_me(main, mid_y - 1, 0.8, 1.0)))
			fil_put_piece_hbdg_px(main, mid_y - 1, mid_x);
		if (main->mod % 2 == 0 && main->put_y == -1 && main->put_x == -1)
			fil_put_piece_hbdg_y(main);
		if (main->put_y == -1 && main->put_x == -1)
			fil_put_piece_bhgd(main);
	}
}

void		fil_put_piece_bas_d(t_filler *main, int mid_x, int mid_y)
{
	if (main->me_y >= mid_y && main->me_x <= mid_x && main->vs_y <= mid_y
			&& main->vs_x >= mid_x)
	{
		//OK me en bas a gauche et vs en haut a droite
		if ((main->put_y == -1 && main->put_x == -1
					&& !fil_put_find_me(main, 0, 0.8, 0.05)))
			fil_put_piece_hbdg_py(main, 1 - main->spiece_y, mid_x);
		if ((main->put_y == -1 && main->put_x == -1
					&& !fil_put_find_me(main, mid_y, 0.5, 1.0)))
			fil_put_piece_bhdg_px(main, mid_y, main->smap_x - 1);
		if (main->mod % 2 == 0 && main->put_y == -1 && main->put_x == -1)
			fil_put_piece_hbdg_y(main);
		if (main->put_y == -1 && main->put_x == -1)
			fil_put_piece_bhgd(main);
	}
	else if (main->me_y >= mid_y && main->me_x <= mid_x && main->vs_y <= mid_y
			&& main->vs_x <= mid_x)
	{
		//OK me en bas a gauche et vs en haut a gauche
		if (main->mod % 2 == 0 && main->put_y == -1 && main->put_x == -1)
			fil_put_piece_hbgd(main);
		if (main->put_y == -1 && main->put_x == -1)
			fil_put_piece_hbdg_py(main, mid_y - 1, main->smap_x - 1);
		if (main->put_y == -1 && main->put_x == -1)
			fil_put_piece_hbgd_y(main);
	}
}
