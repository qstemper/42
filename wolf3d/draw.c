/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 08:02:58 by qstemper          #+#    #+#             */
/*   Updated: 2016/09/28 09:07:49 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	set_color(t_color *color, int red, int green, int blue)
{
	color->red = red;
	color->green = green;
	color->blue = blue;
}

static void	mlx_image_put_pixel(t_env *e, t_coord pt, t_color *color)
{
	if (e->endian)
	{
		e->pxl[pt.yi * e->sizeline + pt.xi * \
			e->bpp / 8] = mlx_get_color_value(e->mlx, color->red);
		e->pxl[pt.yi * e->sizeline + pt.xi * \
			e->bpp / 8 + 1] = mlx_get_color_value(e->mlx, color->green);
		e->pxl[pt.yi * e->sizeline + pt.xi * \
			e->bpp / 8 + 2] = mlx_get_color_value(e->mlx, color->blue);
	}
	else
	{
		e->pxl[pt.yi * e->sizeline + \
			e->bpp / 8 * pt.xi] = mlx_get_color_value(e->mlx, color->blue);
		e->pxl[pt.yi * e->sizeline + \
			e->bpp / 8 * pt.xi + 1] = mlx_get_color_value(e->mlx, color->green);
		e->pxl[pt.yi * e->sizeline + \
			e->bpp / 8 * pt.xi + 2] = mlx_get_color_value(e->mlx, color->red);
	}
}

void		draw(t_env *e, t_color *color, int x)
{
	t_coord	pt;
	t_color	skyfloor;

	pt.xi = x;
	e->pxl = mlx_get_data_addr(e->img, &e->bpp, &e->sizeline, &e->endian);
	set_color(&skyfloor, 128, 128, 128);
	pt.yi = 0;
	while (pt.yi < e->ray.ystart)
	{
		mlx_image_put_pixel(e, pt, &skyfloor);
		pt.yi++;
	}
	pt.yi = e->ray.ystart;
	while (pt.yi < e->ray.yend)
	{
		mlx_image_put_pixel(e, pt, color);
		pt.yi++;
	}
	set_color(&skyfloor, 102, 51, 0);
	pt.yi = e->ray.yend;
	while (pt.yi < HEIGHT)
	{
		mlx_image_put_pixel(e, pt, &skyfloor);
		pt.yi++;
	}
}

void		color(t_env *e, t_color *color)
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
