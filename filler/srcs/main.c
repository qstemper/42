/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclerc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/09 15:22:18 by jclerc            #+#    #+#             */
/*   Updated: 2016/10/02 18:35:25 by jclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	fill_bis(t_filler *fill)
{
	ft_printf("%d %d\n", fill->put_y, fill->put_x);
	if (DEBUG == 1)
	{
		ft_putstr_fd("COORDONNEES ", fill->fd);
		ft_putnbr_fd(fill->put_y, fill->fd);
		ft_putchar_fd(' ', fill->fd);
		ft_putnbr_fd(fill->put_x, fill->fd);
		ft_putchar_fd('\n', fill->fd);
	}
	fill->put_x = -1;
	fill->put_y = -1;
	fill->mod++;
}

int			main(void)
{
	t_filler	fill;

	fil_initfiller(&fill);
	errno = 0;
	fill.fd = open("filler.log", O_RDWR | O_TRUNC | O_CREAT | O_APPEND, 500);
	fil_initvm(&fill);
	if (fill.exit == 1)
		return (EXIT_FAILURE);
	while (1)
	{
		fil_readmap(&fill);
		if (fill.exit == 1)
			return (EXIT_FAILURE);
		fil_readpiece(&fill);
		if (fill.exit == 1)
			return (EXIT_FAILURE);
		fil_put_piece(&fill);
		fill_bis(&fill);
	}
	close(fill.fd);
	return (EXIT_SUCCESS);
}
