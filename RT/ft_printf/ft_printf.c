/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 03:05:25 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/12 19:16:55 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int						ft_printf_skip_color(const char *format)
{
	int							n;

	n = 0;
	while (*format && *format != '}')
	{
		n++;
		format++;
	}
	if (!*format)
		return (0);
	return (n);
}

static int						print_no_format(const char *format)
{
	const char					*cp;
	const char					*tmp;

	cp = format;
	tmp = cp;
	while (*format && *format != '%')
	{
		if (*format == '{')
		{
			if (format != tmp)
				save_buff((void *)tmp, format - tmp);
			ft_printf_apply_color(format);
			format += ft_printf_skip_color(format);
			tmp = format + 1;
			if (!tmp)
				return (format - cp);
		}
		format++;
	}
	save_buff((void *)tmp, format - tmp);
	return (format - cp);
}

int								ft_vlprintf(const char *format, va_list ap)
{
	t_printf_special_function	print_format[NB_SPECIAL_FUNCTION];
	t_printf_set_function		set_mode[NB_MODE_FUNCTION];
	t_printf_mode				mode;
	int							length;
	long int					tlength;

	init_print(print_format);
	init_set(set_mode);
	tlength = 0;
	while (*format)
	{
		length = print_no_format(format);
		tlength += length;
		if (!*(format += length))
			break ;
		ft_bzero((void *)&mode, sizeof(t_printf_mode));
		mode.precision = -1;
		if (*(format += set_format_mode(format, &mode, set_mode, ap)))
			format++;
		tlength += print_format[get_special_index(SPECIAL_CSET, \
				mode.special)](mode, ap);
	}
	return (tlength);
}
