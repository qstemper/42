/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_special_char.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 02:46:05 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/07 10:42:40 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_s(t_printf_mode mode, va_list ap)
{
	char	*cp;
	wchar_t	*w_cp;
	int		size;

	w_cp = NULL;
	if (mode.flag & LONGINT)
	{
		if (!(w_cp = va_arg(ap, wchar_t *)))
			w_cp = L"(null)";
		cp = (char *)ft_memalloc((sizeof(char) * (w_c_len(w_cp) * 4 + 1)));
		if (!cp)
			return (0);
		wide_ctoa(w_cp, cp);
		size = (mode.precision > -1 && (size_t)mode.precision < \
				ft_strlen(cp)) ? (size_t)mode.precision : ft_strlen(cp);
	}
	else
	{
		if (!(cp = va_arg(ap, char *)))
			cp = "(null)";
		size = (mode.precision > -1 && (size_t)mode.precision < \
				ft_strlen(cp)) ? (size_t)mode.precision : ft_strlen(cp);
	}
	mode.sign = '\0';
	return (ft_printf_cs_val(cp, size, mode));
}

int			print_ls(t_printf_mode mode, va_list ap)
{
	mode.flag |= LONGINT;
	return (print_s(mode, ap));
}

int			print_c(t_printf_mode mode, va_list ap)
{
	char	buff[BUFF_SIZE * 4];
	wchar_t	wide_buff[BUFF_SIZE];
	int		size;

	ft_bzero((void *)buff, sizeof(char) * BUFF_SIZE * 4);
	if (mode.flag & LONGINT)
	{
		*wide_buff = va_arg(ap, wint_t);
		*(wide_buff + 1) = L'\0';
		wide_ctoa(wide_buff, buff);
		size = *buff ? ft_strlen(buff) : 1;
	}
	else
	{
		*buff = va_arg(ap, int);
		size = 1;
	}
	mode.sign = '\0';
	return (ft_printf_cs_val(buff, size, mode));
}

int			print_lc(t_printf_mode mode, va_list ap)
{
	mode.flag |= LONGINT;
	return (print_c(mode, ap));
}

int			print_def(t_printf_mode mode)
{
	char	buff[BUFF_SIZE * 4];
	wchar_t wide_buff[BUFF_SIZE];
	int		size;

	ft_bzero((void *)buff, sizeof(char) * BUFF_SIZE);
	if (mode.flag & LONGINT)
	{
		*wide_buff = mode.special;
		*(wide_buff + 1) = L'\0';
		wide_ctoa(wide_buff, buff);
		size = *buff ? ft_strlen(buff) : 1;
	}
	else
	{
		*buff = mode.special;
		size = ft_strlen(buff);
	}
	mode.sign = '\0';
	return (ft_printf_cs_val(buff, size, mode));
}
