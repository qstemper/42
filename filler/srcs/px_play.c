#include "filler.h"

void	play_btlr_px(t_filler *fill, int y, int x)
{
	int i;
	int j;

	i = y;
	while (i >= 1 - fill->spiece_y)
	{
		fill->put_y = i;
		j = x;
		while (j < fill->smap_x)
		{
			fill->put_x = j;
			if (check_play(fill))
				return ;
			j++;
		}
		i--;
	}
	fill->put_y = -1;
	fill->put_x = -1;
}

void	play_btrl_px(t_filler *fill, int y, int x)
{
	int i;
	int j;

	i = y;
	while (i >= 1 - fill->spiece_y)
	{
		fill->put_y = i;
		j = x;
		while (j >= 1 - fill->spiece_x)
		{
			fill->put_x = j;
			if (check_play(fill))
				return ;
			j--;
		}
		i--;
	}
	fill->put_y = -1;
	fill->put_x = -1;
}

void	play_tbrl_px(t_filler *fill, int y, int x)
{
	int i;
	int j;

	i = y;
	while (i < fill->smap_y)
	{
		fill->put_y = i;
		j = x;
		while (j >= 1 - fill->spiece_x)
		{
			fill->put_x = j;
			if (check_play(fill))
				return ;
			j--;
		}
		i++;
	}
	fill->put_y = -1;
	fill->put_x = -1;
}

void	play_tblr_px(t_filler *fill, int y, int x)
{
	int i;
	int j;

	i = y;
	while (i < fill->smap_y)
	{
		fill->put_y = i;
		j = x;
		while (j < fill->smap_x)
		{
			fill->put_x = j;
			if (check_play(fill))
				return ;
			j++;
		}
		i++;
	}
	fill->put_y = -1;
	fill->put_x = -1;
}
