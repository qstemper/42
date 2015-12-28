/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   absolute.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 10:38:58 by qstemper          #+#    #+#             */
/*   Updated: 2015/12/08 10:39:06 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

float	abs(float x)
{
	if (x < 0.0)
		return (-x);
	return (x);
}
