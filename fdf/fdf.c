/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <qstemper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 13:33:14 by qstemper          #+#    #+#             */
/*   Updated: 2015/12/03 11:45:22 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			lstpoint(t_list **listpoint, t_list *list, int cpt)
{
	int		i;
	t_list	*elem;
	t_p3D	point;

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
		elem = ft_lstnew((void *)&point, sizeof(t_p3D));
		if (elem == NULL)
		{
			*listpoint = NULL;
			return (0);
		}
		ft_lstaddback(listpoint, elem);
		list = list->next;
	}
	return (1);
}

int			fdf(char *str, t_list **listpoint)
{
	int		fd;
	int		cpt;
	char	*line;
	t_list	*list;

	if ((fd = open(str, O_RDONLY)) == -1)
		return (0);
	line = NULL;
	cpt = 0;
	while (get_next_line(fd, &line) > 0)
	{
		list = NULL;
		if (lexer(line, &list) != 1)
		{
			free(line);
			return (0);
		}
		if (lstpoint(listpoint, list, cpt++) == 0)
			return (0);
		free(line);
		ft_lstdel(&list, NULL);
	}
	close(fd);
	return (1);
}

int			main(int ac, char **av)
{
	int		ret;
	int		temp;
	t_list	*listpoint;
	t_list	*tmp;

	listpoint = NULL;
	if (ac != 2)
		return (-1);
	temp = 0;
	while (*av[1] != '\0')
	{
		if ((ret = fdf(av[1], &listpoint)) == 0)
			return (-1);
		tmp = listpoint;
		while (tmp)
		{
			if (temp != ((t_p3D *)tmp->content)->y)
				printf("\n");
			printf("[%d]", ((t_p3D *)tmp->content)->z);
			av[1]++;
			temp = ((t_p3D *)tmp->content)->y;
			tmp = tmp->next;
		}
	}
	fdf_mlx();
	return (0);
}
