/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 11:10:17 by sbenning          #+#    #+#             */
/*   Updated: 2017/04/17 12:58:22 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		delete_tab(char ***tab)
{
	int			i;

	i = 0;
	while ((*tab)[i])
	{
		ft_memdel((void **)(*tab + i));
		++i;
	}
	ft_memdel((void **)tab);
}