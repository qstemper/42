/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_diouxpcs_val.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 03:58:28 by qstemper          #+#    #+#             */
/*   Updated: 2016/09/27 04:05:57 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf_dioux_val(uintmax_t ujval, t_ulong ulval, \
		int base, t_printf_mode mode)
{
	int		size;
	int		realsize;
	char	buff[BUFF_SIZE];
	char	*cp;

	ft_bzero(buff, sizeof(char) * BUFF_SIZE);
	cp = buff + BUFF_SIZE;
	if (mode.flag & INTMAX_SIZE)
	{
		if (ujval || mode.precision || (mode.flag & ALT && base == 8))
			cp = tool_ujtoa(ujval, base, mode, cp);
	}
	else
	{
		if (ulval || mode.precision || (mode.flag & ALT && base == 8))
			cp = tool_ultoa(ulval, base, mode, cp);
	}
	size = buff + BUFF_SIZE - cp;
	realsize = size > mode.precision ? size : mode.precision;
	realsize += mode.sign ? 1 : 0;
	realsize += mode.ox[1] ? 2 : 0;
	ft_printf_finaly_print(cp, size, realsize, mode);
	return (mode.width > realsize ? mode.width : realsize);
}

int			ft_printf_p_val(uintmax_t ujval, t_printf_mode mode)
{
	int		size;
	int		realsize;
	char	buff[BUFF_SIZE];
	char	*cp;

	ft_bzero(buff, sizeof(char) * BUFF_SIZE);
	cp = buff + BUFF_SIZE;
	cp = tool_ujtoa(ujval, 16, mode, cp);
	size = buff + BUFF_SIZE - cp;
	realsize = size > mode.precision ? size : mode.precision;
	realsize += 2;
	if (!mode.precision && !ujval)
		realsize -= 1;
	if (mode.precision > -1)
		mode.flag &= ~ZEROPAD;
	ft_printf_finaly_print(cp, size, realsize, mode);
	return (mode.width > realsize ? mode.width : realsize);
}

int			ft_printf_cs_val(char *cp, int size, t_printf_mode mode)
{
	mode.precision = -1;
	ft_printf_finaly_print(cp, size, size, mode);
	return (mode.width > size ? mode.width : size);
}
