/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_view.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 14:54:35 by qstemper          #+#    #+#             */
/*   Updated: 2015/12/16 15:31:21 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float		gap_x(t_env *e)
{
	float	gap;

	gap = GAP_X * e->zoom;
	return (gap);
}

float		gap_y(t_env *e)
{
	float	gap;

	gap = GAP_Y * e->zoom / 4;
	return (gap);
}

float		fdf_view_iso_x(t_env *e, int i, int j)
{
	t_p3d	p;
	float	gx;
	float	gy;

	gx = gap_x(e);
	gy = gap_y(e);
	p.x = (i - (e->x_max / 2)) * gx;
	p.y = (j - ((1 + e->y_max) / 2)) * gy;
	p.x = p.x * cos(30) + p.y * sin(30);
	p.x += 512;
	return ((float)p.x);
}

float		fdf_view_iso_y(t_env *e, int i, int j)
{
	t_p3d	p;

	p.x = (i - ((1 + e->x_max) / 2)) * gap_x(e);
	p.y = (j - (e->y_max / 2)) * gap_y(e);
	p.y = p.y * sin(30) - p.x * cos(30);
	p.y += 512;
	return ((float)p.y);
}
