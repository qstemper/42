#include "frac.h"

int	rgb_creating(int r, int g, int b)
{
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + ((b & 0xff)));
}

void	frac_change(char *name, t_env *e)
{
	if (ft_strcmp("Mandelbrot", name) == 0)
		e->ftl_ptr = &(e->ftl_arr[0]);
	else if (ft_strcmp("Julia", name) == 0)
		e->ftl_ptr = &(e->ftl_arr[1]);
	else if (ft_strcmp("Carpet", name) == 0)
		e->ftl_ptr = &(e->ftl_arr[2]);
	else if (ft_strcmp("B_Ship", name) == 0)
		e->ftl_ptr = &(e->ftl_arr[3]);
	else if (ft_strcmp("Mandelbar", name) == 0)
		e->ftl_ptr = &(e->ftl_arr[4]);
}

void	key_frac_change(int keycode, t_env *e)
{
	if (keycode == KEY_KP_1)
		frac_change("Mandelbrot", e);
	else if (keycode == KEY_KP_2)
		frac_change("Julia", e);
	else if (keycode == KEY_KP_3)
		frac_change("Carpet", e);
	else if (keycode == KEY_KP_4)
		frac_change("b_ship", e);
	else if (keycode == KEY_KP_5)
		frac_change("Mandelbar", e);
}

void	key_color_change(int keycode, t_env *e)
{
	if (keycode == KEY_1)
		change_color(0, e);
	else if (keycode == KEY_2)
		change_color(1, e);
	else if (keycode == KEY_3)
		change_color(2, e);
	else if (keycode == KEY_4)
		change_color(3, e);
}
