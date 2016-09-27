/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wide_ctoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 02:45:43 by qstemper          #+#    #+#             */
/*   Updated: 2016/09/27 02:45:45 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			mask1(unsigned int wide_i, char **s)
{
	unsigned int	mask;
	char			*cp;

	mask = MASK1;
	cp = *s;
	*cp = (mask >> 8) | (((wide_i >> 6) << 27) >> 27);
	*(cp + 1) = ((mask << 24) >> 24) | ((wide_i << 26) >> 26);
	*s += 2;
}

static void			mask2(unsigned int wide_i, char **s)
{
	unsigned int	mask;
	char			*cp;

	mask = MASK2;
	cp = *s;
	*cp = (mask >> 16) | (((wide_i >> 12) << 28) >> 28);
	*(cp + 1) = ((mask << 16) >> 24) | (((wide_i >> 6) << 26) >> 26);
	*(cp + 2) = ((mask << 24) >> 24) | ((wide_i << 26) >> 26);
	*s += 3;
}

static void			mask3(unsigned int wide_i, char **s)
{
	unsigned int	mask;
	char			*cp;

	mask = MASK3;
	cp = *s;
	*cp = (mask >> 24) | (((wide_i >> 18) << 29) >> 29);
	*(cp + 1) = ((mask << 8) >> 24) | (((wide_i >> 12) << 26) >> 26);
	*(cp + 2) = ((mask << 16) >> 24) | (((wide_i >> 6) << 26) >> 26);
	*(cp + 3) = ((mask << 24) >> 24) | ((wide_i << 26) >> 26);
	*s += 4;
}

void				wide_ctoa(wchar_t *wide_s, char *s)
{
	while (*wide_s != L'\0')
	{
		if (*wide_s <= 0x7F)
			*s++ = *wide_s;
		else if (*wide_s <= 0x7FF)
			mask1((unsigned int)*wide_s, &s);
		else if (*wide_s <= 0xFFFF)
			mask2((unsigned int)*wide_s, &s);
		else if (*wide_s <= 0x1FFFFF)
			mask3((unsigned int)*wide_s, &s);
		wide_s++;
	}
	*s = 0;
}
