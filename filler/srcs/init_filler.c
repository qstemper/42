#include "filler.h"

static void	init_vm_choice(t_filler *fill)
{
	if (fill->player == 1)
	{
		fill->pchar = 'O';
		fill->lpchar = 'o';
	}
	else if (fill->player == 2)
	{
		fill->pchar = 'X';
		fill->lpchar = 'x';
	}
	else
	{
		ft_fprintf(2, "BAD PLAYER\n");
		fill->exit = 1;
		return ;
	}
}

void		init_vm(t_filler *fill)
{
	char	**split;
	char	*line;

	split = NULL;
	if (get_next_line(0, &line) != 1)
	{
		fill->exit = 1;
		return ;
	}
	split = ft_strsplit(line, ' ');
	if ((split == NULL) || (ft_strlen(line) < 14) || (ft_strsplit_len(split) != 5))
	{
		ft_fprintf(2, "BAD PLAYER\n");
		fill->exit = 1;
		return ;
	}
	fill->player = ft_atoi(split[2] + 1);
	ft_strsplit_free(&split);
	init_vm_choice(fill);
}

void	init_filler(t_filler *fill)
{
	fill->exit = 0;
	fill->f = -1;
	fill->fd = -1;
	fill->mod = 0;
	fill->player = 0;
	fill->pchar = 0;
	fill->lpchar = 0;
	fill->smap_x = 0;
	fill->smap_y = 0;
	fill->me_x = -1;
	fill->me_y = -1;
	fill->vs_x = -1;
	fill->vs_y = -1;
	fill->spiece_x = 0;
	fill->spiece_y = 0;
	fill->put_x = -1;
	fill->put_y = -1;
	fill->map = NULL;
	fill->piece = NULL;
}
