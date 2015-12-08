/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 10:40:12 by qstemper          #+#    #+#             */
/*   Updated: 2015/12/08 10:40:13 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

float	median(float x, float y, float z)
{
	if ((x > y && x < z) || (x < y && x > z))
		return (x);
	else if ((y > x && y < z) || (y < x && y > z))
		return (y);
	else if ((z > x && z < y) || (z < x && z > y))
		return (z);
}
