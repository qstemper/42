#include "rtv1.h"

void		img_draw(t_env *e, int x, int y, int color)
{
	int	i;
	int	dest;
	int	color_new;

	color_new = mlx_get_color_value(e->mlx, color);
	dest = x * e->bpp + y * e->sizeline;
	i = -1;
	while (++i < e->bpp)
	{
		if (e->endian == 0)
			e->data[dest + i] = color_new >> (i << 3) &0xFF;
		else
			e->data[dest + i] = color_new >> (e->bpp - ((i + 1) << 3)) & 0xFF;
	}
}
