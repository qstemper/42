#include "frac.h"

void	ftl_col_change(int num, t_env *e)
{
	if (num >= 0 && num <= 3)
		e->p_col_ptr = &(e->p_col_arr[num]);
	else
		e->p_col_ptr = &(e->p_col_arr[0]);
}

void	ftl_col_init(t_env *e)
{
	if (!(e->p_col_arr = (t_pal *)malloc(sizeof(t_pal) * 4)))
		ft_malloc_error();
	e->p_col_ptr = NULL;
	e->p_col_arr[0] = (t_pal){0x7AE0F2, 0x1E2A66, 0x1FBF06, 0xA63C7F,
		0x262473, 0x0A3BB0, 0xD94A39, 0x403231, 0x8C5AA6, 0x8BB16C, 0XD9C860};
	e->p_col_arr[1] = (t_pal){0x7AE0F2, 0x752859, 0xF29CD4, 0xA65A8B,
		0x25591F, 0x62A65A, 0x78EDF2, 0x337073, 0xA65A8B, 0x7AF2B5, 0x337352};
	e->p_col_arr[2] = (t_pal){0x000000, 0x090132, 0x04044A, 0x000865,
		0x0B2C89, 0x1752B0, 0x88B4E3, 0xD4EBFB, 0xF1EABE, 0xF6CB5A, 0xFFAA00};
	e->p_col_arr[3] = (t_pal){0xFFFFFF, 0xEEEEEE, 0x000000, 0xCCCCCC,
		0xBBBBBB, 0xAAAAAA, 0x999999, 0x888888, 0x777777, 0x666666, 0x555555};
	e->p_col_ptr = &(e->p_col_arr[2]);
}

int	ftl_get_col(int z, t_pal pal)
{
	int	col;

	z = sin(z) * 100;
	col = pal.col_def;
	if (z < 0)
		col = pal.col_0;
	else if (z >= 0 && z < 10)
		col = pal.col_1;
	else if (z >= 10 && z < 20)
		col = pal.col_2;
	else if (z >= 20 && z < 30)
		col = pal.col_3;
	else if (z >= 30 && z < 40)
		col = pal.col_4;
	else if (z >= 40 && z < 50)
		col = pal.col_5;
	else if (z >= 50 && z < 60)
		col = pal.col_6;
	else if (z >= 60 && z < 70)
		col = pal.col_7;
	else if (z >= 70 && z < 80)
		col = pal.col_8;
	else if (z >= 80)
		col = pal.col_9;
	return (col);
}
