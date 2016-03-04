#include "fractol.h"

int	mandelbrot(t_env *e)
{
	t_cplx	c;
	t_cplx	z;
	float	i;

	c.r = e->dx;
	c.im = e->dy;
	z.r = 0.0;
	z.im = 0.0;
	i = 0.0;
	while (i < e->n && (c.r + c.im) < e->n)
	{
		z.im = 2.0 * z.r * z.im + e->y_diff;
		z.r = c.r - c.im + e->x_diff;
		c.r = squared(z.r);
		c.im = squared (z.im);
		i++;
	}
	if (e->theme < 3)
		i  = calc_frac(i, i - log2(log2(c.r + c.im)), 1.0);
	e->color = fractol_color(i, (e->theme > 2 ? e->theme - 3 : e->theme));
	put_pixel(e);
	return (1);
}

void	launch_mand(t_env *e)
{
	e->y = 0;
	while (e->y < e->img_height)
	{
		e->x = 0;
		while (e->x < e->img_width)
		{
			mandelbrot(e);
			e->x = e->x + 1;
		}
		e->y = e->y + 1;
	}
}
