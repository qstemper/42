/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 04:24:16 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/18 09:15:07 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		init_key(t_env *e)
{
	ft_bzero(e->event.key, sizeof(*key));
}

int			is_key(t_env *e)
{
	int		i;
	int		*key;

	i = 0;
	key = (int *)e->event.key;
	while ((size_t)key - (size_t(e->event.key) < sizeof(* key)))
	{
		if (*key)
			return (1);
		key++;
	}
	return (0);
}
