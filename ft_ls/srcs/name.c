/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 13:22:23 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/13 10:56:23 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*ft_name(char *path)
{
	char	*f;

	if ((f = ft_strrchr(path, '/')) == NULL)
		return (path);
	return (f + 1);
}
