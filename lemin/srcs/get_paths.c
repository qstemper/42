/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 08:28:07 by qstemper          #+#    #+#             */
/*   Updated: 2017/04/20 08:28:09 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	is_forbidden(t_btrack *backtrack)
{
	t_list	*drive;

	drive = backtrack->path;
	while (drive)
	{
		if (backtrack->id == *(int *)drive->content)
			return (1);
		drive = drive->next;
	}
	return (0);
}

static int	get_paths(t_graph *rooms, t_graph *paths,\
						t_cons *rules, t_btrack *backtrack)
{
	int		myid;
	int		i;
	int		size;

	myid = backtrack->id;
	push_step(backtrack);
	if (myid == rules->id_s)
	{
		save_path(paths, backtrack);
		pop_step(backtrack);
		return (0);
	}
	i = -1;
	size = rooms->node[myid].neig_size;
	while (++i < size)
	{
		backtrack->id = rooms->node[myid].neig[i];
		if (is_forbidden(backtrack))
			continue ;
		else if (get_paths(rooms, paths, rules, backtrack))
			return (-1);
	}
	pop_step(backtrack);
	return (0);
}

void		get_paths_by_backtrack(t_graph *rooms, t_graph *paths, \
										t_cons *rules)
{
	t_btrack		backtrack;

	ft_bzero(&backtrack, sizeof(t_btrack));
	backtrack.id = rules->id_e;
	backtrack.path = NULL;
	get_paths(rooms, paths, rules, &backtrack);
}
