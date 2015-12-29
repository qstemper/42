#include "fractol.h"

void	mandelbrot(t_env e, float x, float y)
{
	t_cplx	c;
	t_cplx	z;
	float	tmp;
	int	i;

	while (x < img_x)
	{
		while (y < img_y)
		{
			c.r = x_min + (x / zoom);
			c.im = y_min + (y / zoom);
			z.r = 0.0;
			z.im = 0.0;
			i = 0;
			tmp = z.r;
			z.r = squared(z.r) - squared(z.im) + c.r;
			z.im = 2 * z.im * tmp + c.im;
			i += 1;
			while (module(z) < 2 && i <= ite_max)
				;
			if (i == ite_max)
				mlx_pixel_put(e.mlx, e.img, x, y, BLACK);
			else
				mlx_pixel_put(e.mlx, e.img, x, y, BLUE);
			x++;
		}
		y++;
	}
}
