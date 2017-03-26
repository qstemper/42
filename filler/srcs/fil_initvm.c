/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fil_initvm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclerc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 16:54:44 by jclerc            #+#    #+#             */
/*   Updated: 2016/10/02 17:44:30 by jclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	fil_initvm_choice(t_filler *main)
{
	if (main->player == 1)
	{
		main->pchar = 'O';
		main->lpchar = 'o';
	}
	else if (main->player == 2)
	{
		main->pchar = 'X';
		main->lpchar = 'x';
	}
	else
	{
		ft_putstr("BAD PLAYER\n");
		main->exit = 1;
		return ;
	}
}

void		fil_initvm(t_filler *main)
{
	int		ret;
	char	**split;
	char	*line;

	split = NULL;
	if ((ret = get_next_line(0, &line)) != 1)
	{
		main->exit = 1;
		return ;
	}
	split = ft_strsplit(line, ' ');
	if (split == NULL || ft_strlen(line) < 14 || ft_strsplit_len(split) != 5)
	{
		ft_putstr("BAD PLAYER\n");
		main->exit = 1;
		return ;
	}
	main->player = ft_atoi(split[2] + 1);
	ft_strsplit_free(&split);
	fil_initvm_choice(main);
}
