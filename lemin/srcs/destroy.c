#include "lemin.h"

static void	del_solution(void *content, size_t content_size)
{
	t_sol	*solution;

	solution = (t_sol *)content;
	if (solution->stable)
		free(solution->stable);
	if (solution->queue)
		free(solution->queue);
	(void)content_size;
}

void		destroy_all(t_graph *room, t_graph *path, t_list **sol)
{
	int		i;

	i = -1;
	while (++i < (int)room->size)
	{
		if (room->node[i].neig)
			free(room->node[i].neig);
		if (ACCESS_ROOM_META(room, i)->name)
			free(ACCESS_ROOM_META(room, i)->name);
	}
	if (i)
		free(room->node);
	i = -1;
	while (++i < (int)path->size)
	{
		if (path->node[i].neig)
			free(path->node[i].neig);
		if (ACCESS_PATH_META(path, i)->step)
			free(ACCESS_PATH_META(path, i)->step);
	}
	if (i)
		free(path->node);
	ft_lstdel(sol, del_solution);
}
