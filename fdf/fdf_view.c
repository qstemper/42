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

	j = 0;
	p.x = (i - (e.x_max / 2)) * GAP;
//	p.x *= (root(2) / 2) * (i - j);
	p.x += 256;
	return ((float)p.x);
}

float		fdf_view_iso_y(t_env e, int i, int j)
{
	t_p3D	p;

	p.z = e.mat[j][i];
	p.y = (j - (e.y_max / 2)) * GAP;
	p.y *= root(2 / 3) - ((i + j) / root(6));
	p.y += 256; 
	return ((float)p.y);
}

