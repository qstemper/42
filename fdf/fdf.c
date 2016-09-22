/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <qstemper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 13:33:14 by qstemper          #+#    #+#             */
/*   Updated: 2016/09/23 00:34:31 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			lstpoint(t_list **listpoint, t_list *list, int cpt)
{
	int		i;
	t_list	*elem;
	t_p3d	point;

	i = 0;
	point.y = cpt;
	while (list)
	{
		if (((t_token *)list->content)->typetoken != Number)
		{
			list = list->next;	
			continue ;
		}
		point.x = i++;
		point.z = ft_atoi(((t_token *)list->content)->str);
		elem = ft_lstnew((void *)&point, sizeof(t_p3d));
		if (elem == NULL)
		{
			*listpoint = NULL;
			return (-1);
		}
		ft_lstaddback(listpoint, elem);
		list = list->next;
	}
	return (i - 1);
}

void		fdf_free(int *x, int tmp_x, char *line, t_list *list)
{
	*x = ((tmp_x > *x) ? tmp_x : *x);
	free(line);
	ft_lstdel(&list, NULL);
}

int			fdf_ckecklst(t_list *lst)
{
	t_token	*token;

	if (lst == NULL)
		return (0);
	while (lst)
	{
		token = (t_token *)lst->content;
		if (token->typetoken != Blank)
		{
			if (token->typetoken != Number)
				return (0);
		}
		lst = lst->next;
	}
	return (1);
}

static int	fdf2(char *line, t_list **list)
{
	if (lexer(line, list) != 1)
	{
		free(line);
		return (0);
	}
	if (fdf_ckecklst(*list) == 0)
	{
		ft_lstdel(list, NULL);
		return (0);
	}
	return (1);
}

int			fdf(char *str, t_list **listpoint, int *x, int *y)
{
	int		fd;
	int		cpt;
	int		tmp_x;
	char	*line;
	t_list	*list;

	if ((fd = open(str, O_RDONLY)) == -1)
		return (0);
	line = NULL;
	cpt = 0;
	while (get_next_line(fd, &line) > 0)
	{
		list = NULL;
		if (fdf2(line, &list) == 0)
			return (0);
		if ((tmp_x = lstpoint(listpoint, list, cpt++)) == -1)
			return (0);
		fdf_free(x, tmp_x, line, list);
	}
	close(fd);
	*y = cpt - 1;
	if (*y < 0)
		return (0);
	return (1);
}
