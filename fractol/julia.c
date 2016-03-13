#include "fractol.h"

int	julia(t_env *e, float x0, float y0)
{
	t_cplx	z;
	int	i;
	float	tmp;

	i = 0.0;
	tmp = exp(-root(squared(x0) + squared(y0)));
	while (i < e->n && (x0 + y0) < 4.0)
	{
		z.r = x0;
		z.im = y0;
		x0 = squared(z.r) - squared(z.im) + e->xs;
		y0 = 2.0 * z.r * z.im + e->ys;
		tmp += exp(-root(squared(x0) + squared(y0)));
		i++;
	}
	if (e->theme < 3)
		i = calc_frac(i, tmp, 1.0);
	e->color = fractol_color(i, (e->theme > 2 ? e->theme - 3 : e->theme));
	put_pixel(e);
	return (1);
}

void	launch_julia(t_env *e)
{
	e->y = 0;
	while (e->y < e->height)
	{
		e->x = 0;
		while (e->x < e->width)
		{
			julia(e, dx(e, e->x), dy(e, e->y));
			e->x = e->x + 1;
		}
		e->y = e->y + 1;
	}
}
