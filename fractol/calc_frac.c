#include "fractol.h"

float	calc_frac(float x, float y, float z)
{
	return (x * (1 - z) + y * z);
}

float	dx(t_env *e, int x)
{
	float dx;

	dx = (((e->x_max - e->x_min) * x) / e->height) + e->x_min;
	return (dx);
}

float	dy(t_env *e, int y)
{
	float dy;

	dy = (((e->y_max - e->y_min) * y) / e->height) + e->x_min;
	return (dy);
}
