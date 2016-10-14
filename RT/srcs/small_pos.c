/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_pos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 01:58:07 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/14 02:06:47 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

float		small_pos(float a, float b)
{
	if (a < 0)
		return (b > 0 ? b : INFINITY);
	else if (b < 0)
		return (a > 0 ? a : INFINITY);
	else
		return (a < b ? a : b);
}
