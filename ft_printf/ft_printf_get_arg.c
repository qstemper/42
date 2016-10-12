/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_get_arg.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 02:59:46 by qstemper          #+#    #+#             */
/*   Updated: 2016/09/27 03:59:23 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t	get_sj_arg(va_list ap, t_printf_mode mode)
{
	if (mode.flag & INTMAXT)
		return (va_arg(ap, intmax_t));
	else if (mode.flag & SIZET)
		return ((intmax_t)va_arg(ap, ssize_t));
	else
		return ((intmax_t)va_arg(ap, long long));
}

long		get_s_arg(va_list ap, t_printf_mode mode)
{
	if (mode.flag & LONGINT)
		return (va_arg(ap, long));
	else if (mode.flag & SHORTINT)
		return ((long)(short)va_arg(ap, int));
	else if (mode.flag & CHARINT)
		return ((long)(char)va_arg(ap, int));
	else
		return ((long)va_arg(ap, int));
}

uintmax_t	get_uj_arg(va_list ap, t_printf_mode mode)
{
	if (mode.flag & INTMAXT)
		return (va_arg(ap, uintmax_t));
	else if (mode.flag & SIZET)
		return ((uintmax_t)va_arg(ap, size_t));
	else
		return ((uintmax_t)va_arg(ap, unsigned long long));
}

t_ulong		get_u_arg(va_list ap, t_printf_mode mode)
{
	if (mode.flag & LONGINT)
		return (va_arg(ap, t_ulong));
	else if (mode.flag & SHORTINT)
		return ((t_ulong)(t_ushort)va_arg(ap, int));
	else if (mode.flag & CHARINT)
		return ((t_ulong)(t_uchar)va_arg(ap, int));
	else
		return ((t_ulong)va_arg(ap, t_uint));
}
