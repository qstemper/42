/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_get.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 12:54:06 by sbenning          #+#    #+#             */
/*   Updated: 2017/04/24 10:39:37 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

char				*vm_get_player_name(t_vm *vm, int id)
{
	t_list			*l;

	l = vm->player;
	while (l)
	{
		if (id == ((t_player *)l->content)->id)
			return (((t_player *)l->content)->header.prog_name);
		l = l->next;
	}
	return ("Not a valid player ID");
}
