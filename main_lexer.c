/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_lexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <qstemper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 00:13:57 by qstemper          #+#    #+#             */
/*   Updated: 2015/12/01 00:14:53 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int			main()
{
	char	*s;
	t_list	*list;
	t_list	*tmp;
	int ret;

	s = "rgeiugeiru 46846868      \nrtgeggrrgeg\f\v ";
	list = NULL;
	ret = lexer(s, &list);
	printf("[%d]\n", ret);
	tmp = list;
	while (list)
	{
		printf("[%s] ", assign_token(((t_token *)list->content)->typetoken));
		printf("[%.*s] \n", ((t_token *)list->content)->size, ((t_token *)list->content)->str);
		list = list->next;
	}
	ft_lstdel(&tmp, NULL);
	return (0);
}
