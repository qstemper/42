/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_buff.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 03:19:47 by qstemper          #+#    #+#             */
/*   Updated: 2016/09/27 03:55:13 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	del_buff(t_buff **buff)
{
	if (!buff || !*buff)
		return ;
	if ((*buff)->buff)
		ft_memdel((void **)&(*buff)->buff);
	ft_memdel((void **)buff);
}
