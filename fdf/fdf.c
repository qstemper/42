/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <qstemper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 13:33:14 by qstemper          #+#    #+#             */
/*   Updated: 2015/12/02 17:55:20 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			lstpoint(t_list **listpoint, t_list *list, int cpt)
{
	int		i;
	t_list	*tmp;
	t_list	*elem;

	i = 0;
	tmp = list;
	elem = NULL;
	while (tmp)
	{
		elem = ft_lstnew(ft_atoi(((char *)tmp->content)->str), sizeof(t_p3D));
		if (elem == NULL)
		{
			*listpoint = NULL;
			return (0);
		}
		ft_lstaddback(listpoint, elem);
		((t_p3D *)listpoint->content)->x = i++;
		((t_p3D *)listpoint->content)->y = cpt;
		((t_p3D *)listpoint->content)->z = ((t_p3D *)tmp->content);
		tmp = tmp->next;
	}
	return (1);
}

int			fdf(char *str)
{
	int		fd;
	int		ret;
	int		ret2;
	int		cpt;
	char	*line;
	t_list	*list;
	t_list	*listpoint;
	t_token	*token;

	if (fd = open(str, O_RDONLY) == -1)
		return (0);
	line = NULL;
	lstpoint = NULL;
	cpt = 0;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		list = NULL;
		if ((ret2 = lexer(line, &list)) != 1)
		{
			free(line);
			return (0);
		}
		free(line);
		if(lstpoint(&listpoint, list, cpt++) == 0)
			return (0);
		ft_lstdel(&list, NULL);
	}
	close(fd);
	return (1);
}

int		main(int ac, char **av)
{
	if (ac != 2)
		return (-1);
	while (*av[1] != '\0')
	{
		
		av[1]++;
	}
	return (0);
}
