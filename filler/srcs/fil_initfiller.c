/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fil_initfiller.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclerc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 16:48:38 by jclerc            #+#    #+#             */
/*   Updated: 2016/10/02 17:44:46 by jclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	fil_initfiller(t_filler *main)
{
	main->exit = 0;
	main->f = -1;
	main->fd = -1;
	main->mod = 0;
	main->player = 0;
	main->pchar = 0;
	main->lpchar = 0;
	main->smap_x = 0;
	main->smap_y = 0;
	main->me_x = -1;
	main->me_y = -1;
	main->vs_x = -1;
	main->vs_y = -1;
	main->spiece_x = 0;
	main->spiece_y = 0;
	main->put_x = -1;
	main->put_y = -1;
	main->map = NULL;
	main->piece = NULL;
}
