/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <qstemper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 10:30:49 by qstemper          #+#    #+#             */
/*   Updated: 2015/11/27 13:37:55 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddi(t_list **alst, t_list *new, size_t i)
{
	t_list	*tmp;
	size_t	n;

	if (*alst == NULL || i == 0)
	{
		ft_lstadd(alst, new);
		return ;
	}
	tmp = *alst;
	n = 0;
	while (n < i && tmp->next)
	{
		tmp = tmp->next;
		n++;
	}
	new->next = tmp->next;
	tmp->next = new;
}
