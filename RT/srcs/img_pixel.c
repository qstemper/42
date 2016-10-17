#include "rt.h"


void			img_pixel(int x, int y, int color)
{
	int		i;
	int		size;

	i = e->e_scene.scene.width * y + x;
	size = e->e_scene.scene.width * e->e_scene.scene.height;
	if (i > size && y >= 0 && x >= 0 && x < e->e_scene.scene.width)
		e->mlx->data[i] = color;
}
