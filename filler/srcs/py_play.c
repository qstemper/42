#include "filler.h"

void	play_tblr_py(t_filler *fill, int y, int x)
{
	int i;
	int j;

	j = x;
	while (j < fill->smap_x)
	{
		fill->put_x = j;
		i = y;
		while (i < fill->smap_y)
		{
			fill->put_y = i;
			if (check_play(fill))
				return ;
			i++;
		}
		j++;
	}
	fill->put_y = -1;
	fill->put_x = -1;
}

void	play_tbrl_py(t_filler *fill, int y, int x)
{
	int i;
	int j;

	j = x;
	while (j >= 1 - fill->spiece_x)
	{
		fill->put_x = j;
		i = y;
		while (i < fill->smap_y)
		{
			fill->put_y = i;
			if (check_play(fill))
				return ;
			i++;
		}
		j--;
	}
	fill->put_y = -1;
	fill->put_x = -1;
}

void	play_btrl_py(t_filler *fill, int y, int x)
{
	int i;
	int j;

	j = x;
	while (j >= 1 - fill->spiece_x)
	{
		fill->put_x = j;
		i = y;
		while (i >= 1 - fill->spiece_y)
		{
			fill->put_y = i;
			if (check_play(fill))
				return ;
			i--;
		}
		j--;
	}
	fill->put_y = -1;
	fill->put_x = -1;
}

void	play_btlr_py(t_filler *fill, int y, int x)
{
	int i;
	int j;

	j = x;
	while (j < fill->smap_x)
	{
		fill->put_x = j;
		i = y;
		while (i >= 1 - fill->spiece_y)
		{
			fill->put_y = i;
			if (check_play(fill))
				return ;
			i--;
		}
		j++;
	}
	fill->put_y = -1;
	fill->put_x = -1;
}
