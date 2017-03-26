/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fil_put_piece_haut.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclerc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 19:19:52 by jclerc            #+#    #+#             */
/*   Updated: 2016/10/02 19:59:44 by jclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	fil_put_piece_haut_a(t_filler *main, int mid_x, int mid_y)
{
	if ((main->me_y <= mid_y && main->me_x <= mid_x
				&& main->vs_y >= mid_y && main->vs_x >= mid_x)
			|| (main->me_y <= mid_y && main->me_x <= mid_x
				&& main->vs_y <= mid_y))
	{
		//OK me en haut a gauche et vs en bas a droite
		//OK me en haut a gauche et vs en haut a droite
		//me en haut a gauche et vs en haut a gauche
		if (main->mod % 17 == 0 && (main->put_y == -1 && main->put_x == -1))
			fil_put_piece_hbgd_y(main);
		if (main->mod % 2 == 0 && (main->put_y == -1 && main->put_x == -1))
			fil_put_piece_bhgd_px(main, main->smap_y - 1, mid_x);
		if (main->put_y == -1 && main->put_x == -1)
			fil_put_piece_hbdg_py(main, mid_y, mid_x);
		if (main->put_y == -1 && main->put_x == -1)
			fil_put_piece_hbgd_py(main, mid_y, mid_x);
		if (main->put_y == -1 && main->put_x == -1)
			fil_put_piece_bhdg_py(main, main->smap_y - 1, mid_x);
		if (main->put_y == -1 && main->put_x == -1)
			fil_put_piece_hbgd(main);
	}
}

void	fil_put_piece_haut_b(t_filler *main, int mid_x, int mid_y)
{
	if (main->me_y <= mid_y && main->me_x <= mid_x
			&& main->vs_y >= mid_y && main->vs_x <= mid_x)
	{
		//OK me en haut a gauche et vs en bas a gauche
		if (main->put_y == -1 && main->put_x == -1
				&& !fil_put_find_me(main, main->smap_y - 1, 0.90, 0.05))
			fil_put_piece_bhdg(main);
		if ((main->put_y == -1 && main->put_x == -1
					&& !fil_put_find_me(main, 0, 1.0, 0.05)))
			fil_put_piece_hbgd(main);
		if ((main->put_y == -1 && main->put_x == -1
					&& !fil_put_find_me(main, mid_y, 0.6, 0.95)))
			fil_put_piece_bhgd_px(main, mid_y, 1 - main->spiece_x);
		if (main->mod % 2 == 0 && main->put_y == -1 && main->put_x == -1)
			fil_put_piece_hbgd_py(main, 1 - main->spiece_y, mid_x);
		if (main->mod % 2 == 0 && main->put_y == -1 && main->put_x == -1)
			fil_put_piece_hbdg_py(main, 1 - main->spiece_y, mid_x);
		if (main->mod % 5 == 0 && main->put_y == -1 && main->put_x == -1)
			fil_put_piece_hbdg(main);
		if (main->put_y == -1 && main->put_x == -1)
			fil_put_piece_bhgd(main);
	}
}

void	fil_put_piece_haut_c(t_filler *main, int mid_x, int mid_y)
{
	if (main->me_y <= mid_y && main->me_x >= mid_x
			&& main->vs_y <= mid_y)
	{
		//OK me en haut a droite et vs en haut a gauche
		//me en haut a droite et vs en haut a droite
		if ((main->put_y == -1 && main->put_x == -1
					&& !fil_put_find_me(main, main->smap_y - 1, 0.7, 0.05)))
			fil_put_piece_bhgd(main);
		if (main->mod % 2 == 0 && main->put_y == -1
				&& main->put_x == -1 && !fil_put_find_me(main, mid_y, 0.8, 1.0))
			fil_put_piece_bhdg_px(main, mid_y, main->smap_x - 1);
		if (main->mod % 2 == 0 && main->put_y == -1 && main->put_x == -1)
			fil_put_piece_hbgd_y(main);
		if (main->put_y == -1 && main->put_x == -1)
			fil_put_piece_hbdg_y(main);
	}
}

void	fil_put_piece_haut_d(t_filler *main, int mid_x, int mid_y)
{
	if (main->me_y <= mid_y && main->me_x >= mid_x
			&& main->vs_y >= mid_y && main->vs_x <= mid_x)
	{
		//OK me en haut a droite et vs en bas a gauche
		if ((main->put_y == -1 && main->put_x == -1
					&& !fil_put_find_me(main, main->smap_y - 1, 0.7, 0.05)))
			fil_put_piece_bhdg(main);
		if ((main->put_y == -1 && main->put_x == -1
					&& !fil_put_find_me(main, 0, 0.7, 0.05)))
			fil_put_piece_hbdg(main);
		if (main->mod % 2 == 0 && main->put_y == -1 && main->put_x == -1)
			fil_put_piece_hbdg_py(main, mid_y, mid_x);
		if (main->mod % 2 == 0 && main->put_y == -1 && main->put_x == -1)
			fil_put_piece_hbgd_py(main, mid_y, mid_x);
		if (main->put_y == -1 && main->put_x == -1)
			fil_put_piece_hbgd_y(main);
	}
}

void	fil_put_piece_haut_e(t_filler *main, int mid_x, int mid_y)
{
	if (main->me_y <= mid_y && main->me_x >= mid_x && main->vs_y >= mid_y
			&& main->vs_x >= mid_x)
	{
		//OK me en haut a droite et vs en bas a droite
		if ((main->put_y == -1 && main->put_x == -1
					&& !fil_put_find_me(main, main->smap_y - 1, 0.7, 0.05)))
			fil_put_piece_bhgd(main);
		if ((main->put_y == -1 && main->put_x == -1
					&& !fil_put_find_me(main, 0, 0.7, 0.05)))
			fil_put_piece_hbdg(main);
		if ((main->put_y == -1 && main->put_x == -1
					&& !fil_put_find_me(main, mid_y, 0.7, 1.0)))
			fil_put_piece_hbdg_px(main, mid_y, mid_x);
		if ((main->put_y == -1 && main->put_x == -1
					&& !fil_put_find_me(main, mid_y, 0.7, 1.0)))
			fil_put_piece_hbdg_px(main, mid_y, mid_x);
		if (main->mod % 2 == 0 && main->put_y == -1 && main->put_x == -1)
			fil_put_piece_hbgd_py(main, 1 - main->spiece_y, mid_x);
		if (main->mod % 2 == 0 && main->put_y == -1 && main->put_x == -1)
			fil_put_piece_hbdg_py(main, 1 - main->spiece_y, mid_x);
		if (main->put_y == -1 && main->put_x == -1)
			fil_put_piece_bhdg(main);
	}
}
