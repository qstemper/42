/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <qstemper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 11:29:27 by qstemper          #+#    #+#             */
/*   Updated: 2015/11/26 18:45:57 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

int		main()
{
	t_list	*list;
	t_list	*elem;
	t_list	*tmp;
	t_list	*list2;
	t_list	*list3;
	int		i;

	list = NULL;
	i = 4;
	while (i >= 0)
	{
		elem = ft_lstnew((void *)&i, sizeof(int));
		if (elem == NULL)
			return (1);
		ft_lstaddback(&list, elem);
		i--;
	}
	i = 42;
	elem = ft_lstnew((void *)&i, sizeof(int));
	if (elem == NULL)
		return (1);
	ft_lstaddi(&list, elem, 42);
	list2 = ft_lstreverse(list);
	list3 = ft_lstcpy(list);
	tmp = list;
	printf("List1 :\n");
	while (tmp)
	{
		printf("%i\n", *((int *)tmp->content));
		tmp = tmp->next;
	}
	tmp = list2;
	printf("List2 :\n");
	while (tmp)
	{
		printf("%i\n", *((int *)tmp->content));
		tmp = tmp->next;
	}
	tmp = list3;
	printf("List3 :\n");
	while (tmp)
	{
		printf("%i\n", *((int *)tmp->content));
		tmp = tmp->next;
	}
	ft_lstdel(&list, NULL);
	ft_lstdel(&list2, NULL);
	ft_lstdel(&list3, NULL);
	printf("%s, %s, %s\n", (char *)list, (char *)list2, (char *)list3);
	return (0);
}
