/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_buff.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 03:57:45 by qstemper          #+#    #+#             */
/*   Updated: 2016/09/27 03:57:49 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		exp_buff(t_buff **buff, size_t buff_size)
{
	char	buff_cpy[buff_size];

	if (!buff || !*buff)
		return ;
	ft_strcpy(buff_cpy, (*buff)->buff);
	ft_memdel((void **)&((*buff)->buff));
	if (!((*buff)->buff = (char *)malloc(sizeof(char) * buff_size + 1)))
		return ;
	ft_strcpy((*buff)->buff, buff_cpy);
	(*buff)->buff_size = buff_size;
}
