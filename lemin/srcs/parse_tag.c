/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 08:30:15 by qstemper          #+#    #+#             */
/*   Updated: 2017/04/20 09:01:24 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int					parse_tag(char *line, int *state)
{
	int				i;

	if (*(line + 1) != LEM_COMMENT_CHAR)
		return (LEM_NOERR);
	if (*state < LEM_DEFAULT_STATE)
		return (LEM_NOPOP_ERR);
	i = -1;
	while (g_cmd[++i].cmd)
	{
		if (!ft_strcmp(line + 2, g_cmd[i].cmd))
			*state = g_cmd[i].state;
	}
	return (LEM_NOERR);
}
