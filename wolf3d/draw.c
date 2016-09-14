#include "wolf3d.h"

static void	set_color(t_rgb *color, int red, int green, int blue)
{
	color->red = red;
	color->green = green;
	color->blue = blue;
}

static void	mlx_image_put_pixel(void *mlx, t_img *img, t_coord point, t_rbg *color)
{
	if (e->endian)
	{
			e->pxl[point.yi * e->sizeline + point.xi * e->bpp / 8] = mlx_get_color_value(mlx, color->red);
			e->pxl[point.yi * e->sizeline + point.xi * e->bpp / 8 + 1] = mlx_get_color_value(mlx, color->green);
			e->pxl[point.yi * e->sizeline + point.xi * e->bpp / 8 + 2] = mlx_get_color_value(mlx, color->blue);
	}
	else
	{
		e->pxl[point.yi * e->sizeline + e->bpp / 8 * point.xi] = mlx->get_color_value(mlx, color->blue);
		e->pxl[point.yi * e->sizeline + e->bpp / 8 * point.xi + 1] = mlx->get_color_value(mlx, color->green);
		e->pxl[point.yi * e->sizeline + e->bpp / 8 * point.xi + 2] = mlx->get_color_value(mlx, color->red);
	}
}

void		draw(t_env *e, t_rgb *color, int x)
{
	t_coord	point;
	t_rgb	skyfloor;

	point.xi = x;
	e->pxl = mlx_get_data_addr(e->img, &e->bpp, &e->sizeline, &e->endian);
	set_color(&skyfloor, 128, 128, 128);
	point.yi = 0;
	while (point.yi < e->ray.ystart)
	{
		mlx_image_put_pixel(, &(e->img), point, skyfloor);
		point.yi++;
	}
	point.yi = e->ray.ystart;
	while (point.yi < e->ray.yend)
	{
		mlx_image_put_pixel(e, &(e->img), point, color);
		point.yi++;
	}
	set_color(&skyfloor, 102, 51, 0);
	point.yi = e->ray.yend;
	while (point.yi < HEIGHT)
	{
		mlx_imag_put_pixel(e, &(e->img), point, &skyfloor);
		point.yi+;
	}
}

void		color (t_env *e, t_rgb * color)
{
	if (e->player.wallside == 0)
	{
		if (e->player.step.xi < 0)
				set_color(color, 0, 0, 255);
		else
				set_color(color, 0, 255, 0);
	}
	else
	{
		if (e->player.step.yi < 0)
				set_color(color, 255, 0, 255);
		else
				set_color(color, 255, 255, 0);
	}
}
