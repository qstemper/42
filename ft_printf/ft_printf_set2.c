/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_set2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 03:16:18 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/07 08:05:46 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	set_h(t_printf_mode *mode)
{
	if (mode->flag & SHORTINT)
	{
		mode->flag &= ~SHORTINT;
		mode->flag |= CHARINT;
	}
	else
		mode->flag |= SHORTINT;
	return (1);
}

int	set_l(t_printf_mode *mode)
{
	if (mode->flag & LONGINT)
	{
		mode->flag &= ~LONGINT;
		mode->flag |= LLONGINT;
	}
	else
		mode->flag |= LONGINT;
	return (1);
}

int	set_j(t_printf_mode *mode)
{
	mode->flag |= INTMAXT;
	return (1);
}

int	set_z(t_printf_mode *mode)
{
	mode->flag |= SIZET;
	return (1);
}
