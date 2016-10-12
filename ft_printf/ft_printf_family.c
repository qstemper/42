/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_family.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 04:04:45 by qstemper          #+#    #+#             */
/*   Updated: 2016/09/27 04:04:47 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *format, ...)
{
	int		length;
	va_list	ap;

	va_start(ap, format);
	length = ft_vfprintf(1, format, ap);
	va_end(ap);
	return (length);
}

int			ft_fprintf(int fd, const char *format, ...)
{
	int		length;
	va_list	ap;

	va_start(ap, format);
	length = ft_vfprintf(fd, format, ap);
	va_end(ap);
	return (length);
}

int			ft_sprintf(char *str, const char *format, ...)
{
	int		length;
	va_list	ap;

	va_start(ap, format);
	length = ft_vsprintf(str, format, ap);
	va_end(ap);
	return (length);
}

int			ft_snprintf(char *str, size_t size, const char *format, ...)
{
	int		length;
	va_list	ap;

	va_start(ap, format);
	length = ft_vsnprintf(str, size, format, ap);
	va_end(ap);
	return (length);
}
