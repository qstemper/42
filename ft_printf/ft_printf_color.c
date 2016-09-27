/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 03:01:41 by qstemper          #+#    #+#             */
/*   Updated: 2016/09/27 04:03:26 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	color_attribute_copy(char *buff, int color)
{
	int		i;

	i = -1;
	while (color && ++i < NB_COLOR_ATTRIBUTE)
	{
		if (col_attr(i)->value & color)
		{
			ft_memcpy(buff, col_attr(i)->attribute, \
					ft_strlen(col_attr(i)->attribute));
			buff += ft_strlen(col_attr(i)->attribute);
			color &= ~col_attr(i)->value;
			if (color)
				ft_memcpy(buff++, ";", 1);
		}
	}
	ft_memcpy(buff, "m\0", 2);
}

void		ft_printf_write_color(int color)
{
	char	buff[BUFF_COLOR_SIZE];
	char	*cp;

	ft_bzero((void *)buff, BUFF_COLOR_SIZE);
	cp = buff;
	ft_memcpy(cp, "\033[", 2);
	cp += 2;
	if (!color)
		color |= COL_DEFAULT;
	color_attribute_copy(cp, color);
	save_buff(buff, ft_strlen(buff));
}

int			color_flag(const char *fmt)
{
	int		flag;
	int		i;

	flag = 0;
	while (*fmt && *fmt != '}')
	{
		i = -1;
		if (*fmt == '|')
			fmt++;
		else
		{
			while (++i < NB_COLOR_ATTRIBUTE)
			{
				if (!ft_strncmp(fmt, col_attr(i)->id, col_attr(i)->len))
				{
					flag |= col_attr(i)->value;
					fmt += col_attr(i)->len;
					break ;
				}
			}
		}
		if (i == NB_COLOR_ATTRIBUTE)
			break ;
	}
	return (flag);
}

void		ft_printf_apply_color(const char *format)
{
	int	color;

	color = 0;
	set_color(&color, format);
	ft_printf_write_color(color);
}
