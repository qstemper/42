#include "fractol.h"

int	mandelbrot(void *p)
{
	t_env	*e;
	t_cplx	c;
	t_cplx	z;
	int	i;
	float	tmpr;
	float	tmpim;

	e = (t_env *)p;
	while (e->x < img_x)
	{
		while (e->y < img_y)
		{
			c.r = x_min + e->x * (x_max - x_min) / 320;
			c.im = y_min + e->y * (x_max - x_min) / 320;
			z.r = 0.0;
			z.im = 0.0;
			i = 0;
			while (i < 50)
			{
				tmpr = z.r;
				tmpim = z.im;
				z.r = squared(tmpr) - squared(tmpim) + c.r;
				z.im = 2 * tmpr * tmpim + c.im;
				if (cplxmod(z) >= 2)
					break;
				i++;
			}
			if (cplxmod(z) >= 2)
				mlx_pixel_put(e->mlx, e->win, e->x, e->y, i * BLUE / 50);
			e->y = e->y + 1;
		}
		e->y = 0;
		e->x = e->x + 1;
	}
	return (1);
}
