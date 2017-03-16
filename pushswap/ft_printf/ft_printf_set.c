/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 03:18:01 by qstemper          #+#    #+#             */
/*   Updated: 2016/09/27 04:00:53 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				set_format_mode(const char *format, t_printf_mode *mode, \
		t_printf_set_function *set_mode, va_list ap)
{
	const char	*cp;
	int			index;

	cp = ++format;
	while (*format)
	{
		index = get_mode_index(MODE_CSET, *format);
		if (index == -1)
			break ;
		format += set_mode[index](mode, format, ap);
	}
	mode->special = *format;
	return (format - (cp - 1));
}
