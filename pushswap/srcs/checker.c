/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 10:33:24 by qstemper          #+#    #+#             */
/*   Updated: 2017/03/22 17:29:57 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int		is_sort(t_stack a)
{
	int			i;

	i = -1;
	while (++i < a.size - 1)
	{
		if (a.tab[i] > a.tab[i + 1])
			return (0);
	}
	return (1);
}

static int		check_ins(char *line, t_stack *a, t_stack *b)
{
	int			i;

	i = -1;
	if (!*line)
		return (0);
	while (++i < 11)
	{
		if (ft_strcmp(line, g_ins[i].str) == 0)
		{
			g_ins[i].f(a, b);
			return (0);
		}
	}
	return (1);
}

static void		gnl_loop(t_stack a, t_stack b)
{
	char		*line;
	int			ret;

	while (get_next_line(0, &line) == 1)
	{
		ret = check_ins(line, &a, &b);
		if (ret == 1)
		{
			ft_fprintf(2, "Error\n");
			free(line);
			exit(1);
		}
		free(line);
	}
	if ((ret = is_sort(a)) == 1 && b.size == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int				main(int ac, char **av)
{
	t_stack		a;
	t_stack		b;
	int			i;
	int			size;
	
	if (ac < 2)
		return (0);
	if (check_arg(av) == 0)
	{
		ft_fprintf(2, "Error\n");
		return (0);
	}
	size = ac - 1;
	if (!(a.tab = (int *)ft_memalloc(sizeof(int) * size)))
		ft_fprintf(2, "Error Malloc\n");
	if (!(b.tab = (int *)ft_memalloc(sizeof(int) * size)))
		ft_fprintf(2, "Error Malloc\n");
	a.size = size;
	b.size = 0;
	i = -1;
	while (++i < ac - 1)
		a.tab[i] = ft_atoi(av[i + 1]);
	gnl_loop(a, b);
	destroy(a, b);
	return (0);
}
