/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <qstemper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 10:43:26 by qstemper          #+#    #+#             */
/*   Updated: 2015/12/03 12:29:14 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		fdf_mlx()
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 420, 420, "TEST");
	write(1, "COUCOU\n", 7);
	sleep(5);
	mlx_destroy_window(mlx, win);
	return (1);
}
