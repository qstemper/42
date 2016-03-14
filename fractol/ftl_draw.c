#include "frac.h"

static void	ftl_draw_frac(t_env *e)
{
	ftl_cal_apply(e, e->ftl_ptr, e->ftl_ptr->func);
}

void		ftl_draw_win(char *title, t_env *e)
{
	if (!(e->mlx = mlx_init()))
		ft_error_str_exit("ERROR MLX INITIALIZATION\n");
	if (!(e->win = mlx_new_window(e->mlx, e->win_size_h, e->win_size_w, title)))
		ft_error_str_exit("ERROR CREATING WINWOW\n");
}

void		ftl_draw_reload(t_env *e)
{
	if (!(e->img = mlx_new_image(e->mlx, e->win_size_h, e->win_size_w)))
		ft_error_str_exit("ERROR CREATING IMAGE\n");
	if (!(e->pixel_img = mlx_get_data_addr(e->img, &(e->bpp), &(e->sizeline), &(e->endian))))
		ft_error_str_exit("ERROR OCCURED TO GET DATA ADDRESS\n");
	ftl_draw_frac(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	mlx_destroy_image(e->mlx, e->img);
}

void		ftl_draw_pixel_img(t_point *pt, t_env *e, int col)
{
	int	i;

	i = ((int)pt->x * 4) + ((int)pt->y * e->sizeline);
	e->pixel_img[i] = col;
	e->pixel_img[i + 1] = col >> 8;
	e->pixel_img[i + 2] = col >> 16;
}
