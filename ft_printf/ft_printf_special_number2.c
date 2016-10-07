/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_special_number2.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 02:59:13 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/07 08:10:30 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				print_x(t_printf_mode mode, va_list ap)
{
	uintmax_t	ujval;
	t_ulong		ulval;

	if (!mode.xdigit)
		mode.xdigit = LOW_HEX_CSET;
	if (mode.precision >= 0)
		mode.flag &= ~ZEROPAD;
	mode.sign = '\0';
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
	if ((mode.flag & ALT) && ((mode.flag & INTMAX_SIZE) ? ujval : ulval))
		mode.ox[1] = !ft_strcmp(mode.xdigit, UP_HEX_CSET) ? 'X' : 'x';
	return (ft_printf_dioux_val(ujval, ulval, 16, mode));
}

int				print_lx(t_printf_mode mode, va_list ap)
{
	mode.xdigit = UP_HEX_CSET;
	return (print_x(mode, ap));
}

int				print_o(t_printf_mode mode, va_list ap)
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
		mode.flag &= ~ZEROPAD;
	return (ft_printf_dioux_val(ujval, ulval, 8, mode));
}

int				print_lo(t_printf_mode mode, va_list ap)
{
	mode.flag |= LONGINT;
	return (print_o(mode, ap));
}

int				print_p(t_printf_mode mode, va_list ap)
{
	uintmax_t	ujval;

	ujval = (uintmax_t)(uintptr_t)va_arg(ap, void *);
	mode.flag |= INTMAXT;
	mode.xdigit = LOW_HEX_CSET;
	mode.ox[1] = 'x';
	mode.sign = '\0';
	return (ft_printf_p_val(ujval, mode));
}
