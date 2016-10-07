/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_finaly.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 03:05:52 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/07 10:31:28 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printf_save_pad(int size, t_printf_pad_char padchar)
{
	char	pad[size < 1 ? 0 : size + 1];

	if (size < 1)
		return ;
	ft_memset((void *)pad, padchar ? ' ' : '0', size);
	save_buff(pad, size);
}

void		ft_printf_finaly_print(char *cp, int size, int realsize, \
		t_printf_mode mode)
{
	if (!(mode.flag & (LADJUST | ZEROPAD)))
		ft_printf_save_pad(mode.width - realsize, BlankChar);
	if (mode.sign)
		save_buff(&mode.sign, 1);
	if (mode.ox[1])
	{
		mode.ox[0] = '0';
		save_buff(mode.ox, 2);
	}
	if ((mode.flag & (LADJUST | ZEROPAD)) == ZEROPAD)
		ft_printf_save_pad(mode.width - realsize, ZeroChar);
	ft_printf_save_pad(mode.precision - size, ZeroChar);
	save_buff(cp, ((!mode.precision && (mode.special == 'p') && \
					(*cp == '0')) ? 0 : size));
	if (mode.flag & LADJUST)
		ft_printf_save_pad(mode.width - realsize, BlankChar);
}
