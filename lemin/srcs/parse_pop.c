/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 08:29:52 by qstemper          #+#    #+#             */
/*   Updated: 2017/04/20 08:29:53 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int					parse_pop(char *line, int *state, t_cons *rules)
{
	*state = LEM_DEFAULT_STATE;
	rules->pop = ft_atoi(line);
	return ((rules->pop < 1 ? LEM_SMALLPOP_ERR : LEM_NOERR));
}
