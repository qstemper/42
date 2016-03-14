#include "frac.h"

int	ftl_create_rgb(int r, int g, int b)
{
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + ((b & 0xff)));
}

void	ftl_change_frac(char *name_ftl, t_env *e)
{
	if (ft_strcmp("Mandelbrot", name_ftl) == 0)
		e->ftl_ptr = &(e->ftl_arr[0]);
	else if (ft_strcmp("Julia", name_ftl) == 0)
		e->ftl_ptr = &(e->ftl_arr[1]);
	else if (ft_strcmp("Carpet", name_ftl) == 0)
		e->ftl_ptr = &(e->ftl_arr[2]);
	else if (ft_strcmp("b_ship", name_ftl) == 0)
		e->ftl_ptr = &(e->ftl_arr[3]);
	else if (ft_strcmp("Mandelbar", name_ftl) == 0)
		e->ftl_ptr = &(e->ftl_arr[4]);
}

void	ftl_key_hook_change_frac(int keycode, t_env *e)
{
	if (keycode == KEY_KP_1)
		ftl_change_frac("Mandelbrot", e);
	else if (keycode == KEY_KP_2)
		ftl_change_frac("Julia", e);
	else if (keycode == KEY_KP_3)
		ftl_change_frac("Carpet", e);
	else if (keycode == KEY_KP_4)
		ftl_change_frac("b_ship", e);
	else if (keycode == KEY_KP_5)
		ftl_change_frac("Mandelbar", e);
}

void	ftl_key_hook_change_col(int keycode, t_env *e)
{
	if (keycode == KEY_1)
		ftl_col_change(0, e);
	else if (keycode == KEY_2)
		ftl_col_change(1, e);
	else if (keycode == KEY_3)
		ftl_col_change(2, e);
	else if (keycode == KEY_4)
		ftl_col_change(3, e);
}
