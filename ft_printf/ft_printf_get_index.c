/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_get_index.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 03:00:59 by qstemper          #+#    #+#             */
/*   Updated: 2016/09/27 03:59:30 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			get_mode_index(char *cset, char c)
{
	char	*f;

	f = ft_strchr(cset, c);
	if (f)
		return (f - cset);
	else if (ft_isdigit(c))
		return (NB_MODE_FUNCTION - 1);
	else
		return (-1);
}

int			get_special_index(char *cset, char c)
{
	char	*f;

	f = ft_strchr(cset, c);
	if (f)
		return (f - cset);
	else
		return (NB_SPECIAL_FUNCTION - 1);
}
