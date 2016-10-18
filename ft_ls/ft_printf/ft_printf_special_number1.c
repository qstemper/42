/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_special_number1.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 03:12:31 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/13 18:24:42 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				print_d(t_printf_mode mode, va_list ap)
{
	uintmax_t	ujval;
	t_ulong		ulval;

	if (mode.flag & INTMAX_SIZE)
	{
		ujval = (intmax_t)get_sj_arg(ap, mode);
		ulval = 0;
		if ((intmax_t)ujval < 0 && (mode.sign = '-'))
			ujval = -ujval;
	}
	else
	{
		ulval = (long)get_s_arg(ap, mode);
		ujval = 0;
		if ((long)ulval < 0 && (mode.sign = '-'))
			ulval = -ulval;
	}
	if (mode.precision >= 0)
		mode.flag &= ~ZEROPAD;
	return (ft_printf_dioux_val(ujval, ulval, 10, mode));
}

int				print_ld(t_printf_mode mode, va_list ap)
{
	mode.flag |= LONGINT;
	return (print_d(mode, ap));
}

int				print_u(t_printf_mode mode, va_list ap)
{
	uintmax_t	ujval;
	t_ulong		ulval;

	if (mode.flag & INTMAX_SIZE)
	{
		ujval = get_uj_arg(ap, mode);
		ulval = 0;
	}
	else
	{
		ulval = get_u_arg(ap, mode);
		ujval = 0;
	}
	mode.sign = '\0';
	if (mode.precision >= 0)
		mode.flag = ~ZEROPAD;
	return (ft_printf_dioux_val(ujval, ulval, 10, mode));
}

int				print_lu(t_printf_mode mode, va_list ap)
{
	mode.flag |= LONGINT;
	return (print_u(mode, ap));
}
