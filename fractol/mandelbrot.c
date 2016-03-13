#include "fractol.h"

int	mandelbrot(t_env *e)
{
	t_cplx	z;
	t_cplx	c;
	float	tmp;
	int	i;
	
	z.r = 0.0;
	z.im = 0.0;
	c.r = e->x_min + (e->x_max - e->x_min) / width * e->x;
	c.im = e->y_min + (e->y_max - e->y_min) / height * e->y;
	i = 0;
	while (cplxmod(z) < 2 && i < e->n)
	{
		tmp = z.r;
		z.r = squared(z.r) - squared(z.im) + c.r;
		z.im = 2.0 * tmp * z.im + c.im;
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
	e->x = 0;
	while (e->x < e->width)
	{
		e->y = 0;
		while (e->y < e->height)
		{
		printf("%d\n", e->y);
			mandelbrot(e);
			e->x = e->x + 1;
		}
		e->y = e->y + 1;
	}
}
