#include "filler.h"

static void	debug(t_filler *fill)
{
	ft_printf("%d %d\n", fill->put_y, fill->put_x);
	if (O_DEBUG == 1)
		ft_printf("COORDINATES %d %d\n", fill->put_y, fill->put_x);
	fill->put_x = -1;
	fill->put_y = -1;
	fill->mod++;
}

int			main(void)
{
	t_filler	fill;

	init_filler(&fill);
	errno = 0;
	fill.fd = open("filler.log", O_RDWR | O_TRUNC | O_CREAT | O_APPEND, 500);
	init_vm(&fill);
	if (fill.exit == 1)
		return (EXIT_FAILURE);
	while (1)
	{
		read_map(&fill);
		if (fill.exit == 1)
			return (1);
		read_play(&fill);
		if (fill.exit == 1)
			return (1);
		play(&fill);
		debug(&fill);
	}
	close(fill.fd);
	return (0);
}
