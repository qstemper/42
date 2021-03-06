/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_view.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 14:54:35 by qstemper          #+#    #+#             */
/*   Updated: 2016/09/28 07:24:59 by qstemper         ###   ########.fr       */
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

	gap = GAP_Y * e->zoom;
	return (gap);
}

float		fdf_view_iso_x(t_env *e, int i, int j)
{
	t_p3d	p;
	float	gx;

	gx = gap_x(e);
	i -= (e->x_max + 1) / 2;
	j -= (e->y_max + 1) / 2;
	p.x = ((sqrt(2.0) / 2.0) * ((float)i - (float)j)) * gx;
	p.x = p.x + 512.0;
	return (p.x);
}

float		fdf_view_iso_y(t_env *e, int i, int j)
{
	t_p3d	p;
	float	gy;

	p.z = e->mat[j][i];
	gy = gap_y(e);
	i -= (e->x_max + 1) / 2;
	j -= (e->y_max + 1) / 2;
	p.y = (sqrt(2.0) / 3.0) * -p.z;
	p.y = p.y + (1.0 / sqrt(6.0)) * ((float)i + (float)j);
	p.y = p.y * gy;
	p.y += 512.0;
	return (p.y);
}
