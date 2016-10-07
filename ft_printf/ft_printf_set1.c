/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_set1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 03:16:39 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/07 08:05:10 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	set_space(t_printf_mode *mode)
{
	if (!mode->sign)
		mode->sign = ' ';
	return (1);
}

int	set_plus(t_printf_mode *mode)
{
	mode->sign = '+';
	return (1);
}

int	set_alt(t_printf_mode *mode)
{
	mode->flag |= ALT;
	return (1);
}

int	set_minus(t_printf_mode *mode)
{
	mode->flag |= LADJUST;
	return (1);
}

int	set_zero(t_printf_mode *mode)
{
	mode->flag |= ZEROPAD;
	return (1);
}
