#include "filler.h"

static void	read_play_free(t_filler *fill)
{
	int i;

	if (fill->piece == NULL)
		return ;
	i = 0;
	while (i <= fill->spiece_y)
	{
		ft_strdel(&fill->piece[i]);
		i++;
	}
	free(fill->piece);
	fill->piece = NULL;
}

static void	read_play_debug(t_filler *fill, int choice, int i)
{
	if (O_DEBUG == 1 && choice == 1)
		ft_printf("SIZE PIECE %d %d\n", fill->spiece_y, fill->spiece_x);
	if (O_DEBUG == 1 && choice == 2)
		ft_printf("%s PIECE\n", fill->piece[i]);
}

static void	read_error(t_filler *fill)
{
	int		i;
	int		ret;
	char	*line;

	i = 0;
	while (i < fill->spiece_y)
	{
		errno = 0;
		if ((ret = get_next_line(0, &line)) != 1)
		{
			fill->exit = 1;
			return ;
		}
		fill->piece[i] = ft_strdup(line);
		read_play_debug(fill, 2, i);
		ft_strdel(&line);
		filler_error(1);
		i++;
	}
}

void		read_play(t_filler *fill)
{
	int		ret;
	int		i;
	char	**split;
	char	*line;

	i = 0;
	read_play_free(fill);
	if ((ret = get_next_line(0, &line)) != 1)
	{
		fill->exit = 1;
		return ;
	}
	split = ft_strsplit(line, ' ');
	fill->spiece_y = ft_atoi(split[1]);
	fill->spiece_x = ft_atoi(split[2]);
	ft_strsplit_free(&split);
	read_play_debug(fill, 1, i);
	if (!(fill->piece = (char**)malloc(sizeof(fill->piece) * \
				(fill->spiece_y + 1))))
		filler_error(0);
	while (i <= fill->spiece_y)
		fill->piece[i++] = NULL;
	read_error(fill);
}
