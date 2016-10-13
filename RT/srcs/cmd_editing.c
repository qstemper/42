/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_editing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 17:12:47 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/13 17:30:34 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	cmd_editing(void)
{
	env->frame.fast_mode = 1;
	env->frame.scene_refresh = clock();
	env->frame.block = 0;
}
