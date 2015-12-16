/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <qstemper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 13:33:14 by qstemper          #+#    #+#             */
/*   Updated: 2015/12/16 15:30:36 by qstemper         ###   ########.fr       */
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
		if (lexer(line, &list) != 1)
		{
			free(line);
			return (0);
		}
		if ((tmp_x = lstpoint(listpoint, list, cpt++)) == -1)
			return (0);
		fdf_free(x, tmp_x, line, list);
	}
	close(fd);
	*y = cpt - 1;
	return (1);
}

int			main(int ac, char **av)
{
	int		ret;
	int		fmlx;
	int		x;
	int		y;
	t_list	*listpoint;

	listpoint = NULL;
	x = 0;
	y = 0;
	if (ac != 2)
		return (-1);
	if ((ret = fdf(av[1], &listpoint, &x, &y)) == 0)
		return (-1);
	if (!(fmlx = fdf_mlx(&listpoint, av[1], x, y)))
		return (-1);
	return (0);
}
