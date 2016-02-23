/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   power.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 10:43:42 by qstemper          #+#    #+#             */
/*   Updated: 2015/12/08 10:43:44 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

float	power(float x, int pow)
{
	if (pow == 0)
		return (1.0);
	else if (pow == 1)
		return (x);
	else if (pow >= 2)
		return (x * power(x, pow - 1));
	return (1 / (power(x, -pow)));
}
