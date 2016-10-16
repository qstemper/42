/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_diaph.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/16 14:13:23 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/16 14:17:23 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include		light_diaph(t_light_color *light, float diaph)
{
	t_color		color;

	color.red = (unsigned char)(fmin((light->red / diaph), 1.0) * 255);
	color.green = (unsigned char)(fmin((light->green / diaph), 1.0) * 255);
	color.blue = (unsigned char)(fmin((light->blue / diaph), 1.0) * 255);
	return (color.color);
}
