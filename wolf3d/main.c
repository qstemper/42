/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 13:16:06 by qstemper          #+#    #+#             */
/*   Updated: 2016/09/28 17:42:10 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	read_option(t_env *e, int ac, char **av)
{
	if (ac != 2)
		error_arg();
	if (open_file(e, av[1]) == 0)
		error_map();
}

int			main(int ac, char **av)
{
	t_env	*e;

	e = init_env();
	read_option(e, ac, av);
	if (!(e->mlx.win = mlx_new_window(e->mlx.mlx, WIDTH, HEIGHT, "WOLF3D")))
	{
		ft_putendl("ERROR CREATING WINDOW");
		return (-1);
	}
	mlx_do_key_autorepeatoff(e->mlx.mlx);
	mlx_loop_hook(e->mlx.mlx, loop_hook, e);
	mlx_hook(e->mlx.win, PRESS, PRESS_MASK, key_press, e);
	mlx_key_hook(e->mlx.win, key_hook, e);
	mlx_loop(e->mlx.mlx);
	return (0);
}
