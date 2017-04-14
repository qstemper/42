/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 10:40:47 by qstemper          #+#    #+#             */
/*   Updated: 2017/04/14 10:40:49 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist			*ft_dlstnew(const void *content, size_t content_size)
{
	t_dlist		*new;

	if (!(new = (t_dlist *)malloc(sizeof(t_dlist))))
		return (NULL);
	new->n = NULL;
	new->p = NULL;
	if (!content)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		if (!(new->content = malloc(content_size)))
		{
			free(new);
			return (NULL);
		}
		new->content = ft_memcpy(new->content, content, content_size);
		new->content_size = content_size;
	}
	return (new);
}
