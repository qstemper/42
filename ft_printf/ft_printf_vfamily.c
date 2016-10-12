/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_vfamily.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 03:03:59 by qstemper          #+#    #+#             */
/*   Updated: 2016/09/27 03:52:44 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_vfprintf(int fd, const char *format, va_list ap)
{
	int		length;

	length = ft_vlprintf(format, ap);
	if (length != -1)
		flush_fd(fd);
	return (length);
}

int			ft_vsprintf(char *str, const char *format, va_list ap)
{
	int		length;

	length = ft_vlprintf(format, ap);
	if (length != -1)
		flush_str(str);
	return (length);
}

int			ft_vsnprintf(char *str, size_t size, const char *format, va_list ap)
{
	int		length;

	length = ft_vlprintf(format, ap);
	if (length != -1)
		flush_nstr(str, size);
	if (length > 0 && length > (int)size)
		return ((int)size);
	else
		return (length);
}
