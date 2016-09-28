/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <qstemper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 11:24:35 by qstemper          #+#    #+#             */
/*   Updated: 2016/09/28 07:20:04 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			**matrix_crea(t_env e)
{
	int		**matrix;
	int		j;

	j = 0;
	matrix = NULL;
	if ((matrix = (int **)malloc(sizeof(int *) * (e.y_max + 1))) == NULL)
		return (matrix);
	while (j <= e.y_max)
	{
		if ((matrix[j] = (int *)malloc(sizeof(int) * (e.x_max + 1))) == NULL)
			return (matrix);
		j++;
	}
	return (matrix);
}

int			**matrix_init(t_env e)
{
	int		i;
	int		j;

	j = 0;
	if ((e.mat = matrix_crea(e)) == NULL)
		return (e.mat);
	while (j <= e.y_max)
	{
		i = 0;
		while (i <= e.x_max)
		{
			e.mat[j][i] = INT_MIN;
			i++;
		}
		j++;
	}
	return (e.mat);
}

int			**matrix_fill(t_env e)
{
	t_p3d	*tmp;

	if ((e.mat = matrix_init(e)) == NULL)
		return (e.mat);
	while (e.list)
	{
		tmp = (t_p3d *)e.list->content;
		e.mat[(int)tmp->y][(int)tmp->x] = (int)tmp->z;
		e.list = e.list->next;
	}
	return (e.mat);
}
