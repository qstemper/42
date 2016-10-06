/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 07:40:03 by qstemper          #+#    #+#             */
/*   Updated: 2016/09/29 07:26:51 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frac.h"

static void	frac_draw(t_env *e)
{
	color_apply(e, e->ptr, e->ptr->func);
}

void		open_window(char *title, t_env *e)
{
	if (!(e->mlx = mlx_init()))
		ft_putendl("ERROR MLX INITIALIZATION");
	if (!(e->win = mlx_new_window(e->mlx, e->height, e->width, title)))
		ft_putendl("ERROR CREATING WINWOW");
}

void		draw_img(t_env *e)
{
	if (!(e->img = mlx_new_image(e->mlx, e->height, e->width)))
		ft_putendl("ERROR CREATING IMAGE");
	if (!(e->pixel_img = mlx_get_data_addr(e->img, &(e->bpp), \
					&(e->sizeline), &(e->endian))))
		ft_putendl("ERROR OCCURED TO GET DATA ADDRESS");
	frac_draw(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	mlx_destroy_image(e->mlx, e->img);
}

void		pixel_draw_img(t_point *pt, t_env *e, int col)
{
	int	i;

	i = ((int)pt->x * 4) + ((int)pt->y * e->sizeline);
	e->pixel_img[i] = col;
	e->pixel_img[i + 1] = col >> 8;
	e->pixel_img[i + 2] = col >> 16;
}
