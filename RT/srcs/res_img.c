/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   res_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 07:39:51 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/18 08:05:02 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		res_light(int x, int y, t_light_color *light, t_env *e)
{
	int		i;
	int		size;

	i = e->e_scene->scene->width * y + x;
	size = e->e_scene->scene->width * e->e_scene->scene->height;
	if (i < size && x >= 0 && y >= 0 && x < e->e_scene->scene->width)
	{
		e->e_scene->res[i].red = light->red;
		e->e_scene->res[i].green = light->green;
		e->e_scene->res[i].blue = light->blue;
	}
}

void		fast_res_light(int x, int y, t_light_color *light, t_env *e)
{
	int		i;
	int		j;
	int		k;
	int		l;
	int		size;

	k = e->e_scene->scene->width * y + x;
	size = e->e_scene->scene->width * e->e_scene->scene->height;
	if (k < size && y >= 0 && x >= 0 && x < e->e_scene->scene->width)
	{
		i = -1;
		while (++i < RES_PREC)
		{
			j = -1;
			while (++j < RES_PREC)
			{
				l = k + j + i * e->e_scene->scene->width;
				e->e_scene->res[l].red = light->red;
				e->e_scene->res[l].green = light->green;
				e->e_scene->res[l].blue = light->blue;
			}
		}
	}
}

void		clean_res_light(int x, int y, t_env *e)
{
	int		i;
	int		size;

	i = e->e_scene->scene->width * y + x;
	size = e->e_scene->scene->width * e->e_scene->scene->height;
	if (i < size && x >= 0 && y >= 0 && x < e->e_scene->scene->width)
	{
		e->e_scene->res[l].red = 0;
		e->e_scene->res[l].green = 0;
		e->e_scene->res[l].blue = 0;
	}
}

void		img_res(t_env *e)
{
	int		i;
	int		j;

	i = -1;
	while (++i < e->e_scene->scene->width)
	{
		j = -1;
		while (++j < e->e_scene->scene->height)
		{
			img_pixel(j, i, light_diaph(e->res[i * \
						e->e_scene->scene->width + x], \
						e->e_scene->scene->diaph));
		}
	}
	e->frame->img_refresh = clock();
	mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, e->mlx.img, 0, 0);
}
