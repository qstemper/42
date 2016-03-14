#include "frac.h"

static void	frac_draw(t_env *e)
{
	color_apply(e, e->ftl_ptr, e->ftl_ptr->func);
}

void		open_window(char *title, t_env *e)
{
	if (!(e->mlx = mlx_init()))
		print_error_ex("ERROR MLX INITIALIZATION\n");
	if (!(e->win = mlx_new_window(e->mlx, e->win_size_h, e->win_size_w, title)))
		print_error_ex("ERROR CREATING WINWOW\n");
}

void		draw_img(t_env *e)
{
	if (!(e->img = mlx_new_image(e->mlx, e->win_size_h, e->win_size_w)))
		print_error_ex("ERROR CREATING IMAGE\n");
	if (!(e->pixel_img = mlx_get_data_addr(e->img, &(e->bpp), &(e->sizeline), &(e->endian))))
		print_error_ex("ERROR OCCURED TO GET DATA ADDRESS\n");
	frac_draw(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	mlx_destroy_image(e->mlx, e->img);
}

void		pixel_draw_img(t_point *pt, t_env *e, int col)
{
	int	i;

	i = ((int)pt->x * 4) + ((int)pt->y * e->sizeline);
	e->pixel_img[i] = col;
	e->pixel_img[i + 1] = col >> 8;
	e->pixel_img[i + 2] = col >> 16;
}
