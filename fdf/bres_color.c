/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bres_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 23:30:08 by qstemper          #+#    #+#             */
/*   Updated: 2016/09/28 07:31:05 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		bres_color(int c1, int c2)
{
	int	c;

	if (!c1 || !c2)
		return (BLACK);
	if (c1 != c2)
	{
		if (c1 == WHITE && c2 > GREEN)
			c = c2 + 0x008800;
		else if (c2 == WHITE && c1 > GREEN)
			c = c1 + 0x008800;
		else if (c1 == WHITE && c2 < GREEN)
			c = c2 + 0x008800;
		else if (c2 == WHITE && c1 < GREEN)
			c = c1 + 0x008800;
		else
			c = ((c1 + c2) / 2);
	}
	else
		c = c1;
	return (c);
}
