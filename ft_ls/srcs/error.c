/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 08:20:54 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/13 13:20:01 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			error(char *key, char *msg)
{
	int		cp;

	if (!errno)
		return (errno);
	cp = errno;
	errno = 0;
	ft_fprintf(2, "%s: %s: %s\n", key, msg, strerror(cp));
	return (cp);
}
