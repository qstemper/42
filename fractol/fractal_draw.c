#include "fractol.h"

t_vector3D	fractol_color(float x, int theme)
{
	t_vector3D	color;

	color.x = 0.5 + 0.5 * cosinus(3.0 + x * 0.15 + (theme == 0));
	color.y = 0.5 + 0.5 * cosinus(3.0 + x * 0.15 + (theme == 1));
	color.z = 0.5 + 0.5 * cosinus(3.0 + x * 0.15 + (theme == 2));
	return (color);
}

void	put_pixel(t_env *e)
{
	int	pos;

	pos = (e->x * e->bpp / 8) + (e->y * e->sizeline);
	e->data[pos] = ((int)(e->color.z * 256) % 256);
	e->data[pos + 1] = ((int)(e->color.z * 256) % 256);
	e->data[pos + 2] = ((int)(e->color.z * 256) % 256);
}
