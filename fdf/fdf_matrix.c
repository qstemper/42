#include "fdf.h"

int		**matrix_crea(int x, int y)
{
	int	**matrix;
	int	j;

	*matrix = NULL;
	if ((matrix = (int **)malloc(sizeof((int *) * y))) == NULL)
		return (matrix);
	while (j <= y)
	{
		if ((matrix[j] = (int *)malloc(sizeof(int * x))) == NULL)
			return (matrix);
		j++;
	}
	return (matrix);
}

int		**matrix_init()
{
	t_env	e;
	int	i;
	int	j;

	j = 0;
	if ((e.mat = matrix_crea(e.x_max, e.y_max)) == 	NULL)
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

int		**matrix_t(t_list *listpoint)
{
	t_env	e;

	if ((e.mat = matrix_init()) == NULL)
		return (e.mat);
	while (listpoint)
	{
		e.mat[listpoint->point.x][listpoint->point.y] = listpoint->point.z;
		listpoint = listpoint->next;
	}
	return (e.mat);
}
