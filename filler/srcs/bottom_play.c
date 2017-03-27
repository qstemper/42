#include "filler.h"

static void	bottom_play1_1(t_filler *fill, int mid_x, int mid_y)
{
	if (fill->me_y >= mid_y && fill->me_x >= mid_x
			&& fill->vs_y <= mid_y && fill->vs_x >= mid_x)
	{
		if ((fill->put_y == -1 && fill->put_x == -1
					&& !find_me(fill, fill->smap_y - 1, 0.7, 0.5)))
			play_btlr(fill);
		if (fill->put_y == -1 && fill->put_x == -1)
			play_tblr(fill);
	}
}

void		bottom_play1(t_filler *fill, int mid_x, int mid_y)
{
	if (fill->me_y >= mid_y && fill->me_x >= mid_x && fill->vs_y <= mid_y
			&& fill->vs_x <= mid_x)
	{
		if (fill->put_y == -1 && fill->put_x == -1
				&& !find_me(fill, 0, 0.1, 0.05))
			play_tblr(fill);
		if ((fill->put_y == -1 && fill->put_x == -1
					&& !find_me(fill, fill->smap_y - 1, 0.7, 0.5)))
			play_btrl(fill);
		if (fill->put_y == -1 && fill->put_x == -1
				&& !find_me(fill, 0, 0.6, 0.1))
			play_tblr_y(fill);
		if (fill->mod % 2 == 0 && fill->put_y == -1 && fill->put_x == -1)
			play_tbrl_px(fill, 1 - fill->spiece_y, mid_x);
		if (fill->mod % 5 == 0 && fill->put_y == -1 && fill->put_x == -1)
			play_tbrl_y(fill);
		if (fill->put_y == -1 && fill->put_x == -1)
			play_btlr_y(fill);
	}
	bottom_play_1_1(fill, mid_x, mid_y);
}

void		bottom_play2(t_filler *fill, int mid_x, int mid_y)
{
	if (fill->me_y >= mid_y && fill->me_x >= mid_x && fill->vs_y >= mid_y)
	{
		if (fill->put_y == -1 && fill->put_x == -1
				&& !find_me(fill, 0, 0.1, 0.05))
			play_tblr(fill);
		if ((fill->put_y == -1 && fill->put_x == -1
					&& !find_me(fill, fill->smap_y - 1, 0.7, 0.5)))
			play_btrl(fill);
		if (fill->put_y == -1 && fill->put_x == -1
				&& !find_me(fill, 0, 0.6, 0.1))
			play_tblr_y(fill);
		if (fill->mod % 2 == 0 && fill->put_y == -1 && fill->put_x == -1)
			play_tbrl_px(fill, 1 - fill->spiece_y, mid_x);
		if (fill->mod % 5 == 0 && fill->put_y == -1 && fill->put_x == -1)
			play_tbrl_y(fill);
		if (fill->put_y == -1 && fill->put_x == -1)
			play_btlr_y(fill);
	}
}

void		bottom_play3(t_filler *fill, int mid_x, int mid_y)
{
	if (fill->me_y >= mid_y && fill->me_x <= mid_x && fill->vs_y >= mid_y)
	{
		if ((fill->mod % 2 == 0 && fill->put_y == -1 && fill->put_x == -1
					&& !find_me(fill, 0, 1.0, 0.05)))
			play_tbrl_y(fill);
		if ((fill->put_y == -1 && fill->put_x == -1
					&& !find_me(fill, 0, 1.0, 0.05)))
			play_tbrl(fill);
		if ((fill->put_y == -1 && fill->put_x == -1
					&& !find_me(fill, fill->smap_y - 1, 1.0, 0.05)))
			play_btlr(fill);
		if ((fill->put_y == -1 && fill->put_x == -1
					&& !find_me(fill, mid_y - 1, 0.8, 0.6)))
			play_tbrl_py(fill, mid_y - 1, fill->smap_x - 1);
		if ((fill->put_y == -1 && fill->put_x == -1
					&& !find_me(fill, mid_y - 1, 0.8, 1.0)))
			play_tbrl_px(fill, mid_y - 1, mid_x);
		if (fill->mod % 2 == 0 && fill->put_y == -1 && fill->put_x == -1)
			play_tbrl_y(fill);
		if (fill->put_y == -1 && fill->put_x == -1)
			play_btlr(fill);
	}
}

void		bottom_play4(t_filler *fill, int mid_x, int mid_y)
{
	if (fill->me_y >= mid_y && fill->me_x <= mid_x && fill->vs_y <= mid_y
			&& fill->vs_x >= mid_x)
	{
		if ((fill->put_y == -1 && fill->put_x == -1
					&& !find_me(fill, 0, 0.8, 0.05)))
			play_tbrl_py(fill, 1 - fill->spiece_y, mid_x);
		if ((fill->put_y == -1 && fill->put_x == -1
					&& !find_me(fill, mid_y, 0.5, 1.0)))
			play_btrl_px(fill, mid_y, fill->smap_x - 1);
		if (fill->mod % 2 == 0 && fill->put_y == -1 && fill->put_x == -1)
			play_tbrl_y(fill);
		if (fill->put_y == -1 && fill->put_x == -1)
			play_btlr(fill);
	}
	else if (fill->me_y >= mid_y && fill->me_x <= mid_x && fill->vs_y <= mid_y
			&& fill->vs_x <= mid_x)
	{
		if (fill->mod % 2 == 0 && fill->put_y == -1 && fill->put_x == -1)
			play_tblr(fill);
		if (fill->put_y == -1 && fill->put_x == -1)
			play_tbrl_py(fill, mid_y - 1, fill->smap_x - 1);
		if (fill->put_y == -1 && fill->put_x == -1)
			play_tblr_y(fill);
	}
}
