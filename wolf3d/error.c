/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 13:29:30 by qstemper          #+#    #+#             */
/*   Updated: 2016/09/29 07:37:55 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	error_malloc(void)
{
	ft_putendl("ERROR ALLOCATION MEMORY");
	exit(1);
}

void	error_arg(void)
{
	ft_putendl("Argument provided isn't correct");
	ft_putendl("Use the following prototype : <filename> <map>");
	exit(1);
}

void	error_map(void)
{
	ft_putendl("Error in the map used");
	exit(1);
}
