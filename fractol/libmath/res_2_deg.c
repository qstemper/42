/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   res_2_deg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 10:45:37 by qstemper          #+#    #+#             */
/*   Updated: 2015/12/08 10:46:58 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

float	res_2_deg_sol1(float a, float b, float c)
{
	float	delta;
	float	res;

	if (a == 0.0)
		return (res_1_deg(b, c));
	delta = squared(b) - (4.0 * a * c);
	if (delta < 0.0)
	{
		write(1, "Imaginary solutions\n", 20);
		return (delta);
	}
	else if (delta == 0.0)
		res = (-b / (2.0 * a));
	else
		res = (-b + root(delta)) / (2 * a);
	return (res);
}

float	res_2_deg_sol2(float a, float b, float c)
{
	float	delta;
	float	res;

	if (a == 0.0)
		return (res_1_deg(b, c));
	delta = squared(b) - (4.0 * a * c);
	if (delta < 0.0)
	{
		write(1, "Imaginary solutions\n", 20);
		return (delta);
	}
	else if (delta == 0.0)
		res = (-b / (2.0 * a));
	else
		res = (-b - root(delta)) / (2 * a);
	return (res);
}
