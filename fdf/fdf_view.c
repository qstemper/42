/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_view.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 14:54:35 by qstemper          #+#    #+#             */
/*   Updated: 2015/12/08 17:14:18 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float		fdf_view_iso_x(t_env e, int i, int j)
{
	t_p3D	p;

	p.x = (i - (e.x_max / 2.0)) * GAP + 512.0;
	p.x *= (root(2.0) / 2.0) * (i - j);
	return ((float)p.x);
}

float		fdf_view_iso_y(t_env e, int i, int j)
{
	t_p3D	p;

	p.z = e.mat[j][i];
	p.y = (j - (e.y_max / 2.0)) * GAP + 512.0;
	p.y *= (root(2.0 / 3.0) * p.z) - ((i + j) / root(6.0));
	return ((float)p.y);
}

