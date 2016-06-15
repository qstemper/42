#include "rtv1.h"

void	open_window(char *title, t_env *e)
{
	if(!(e->mlx = mlx_init()))
		ft_putendl("ERROR MLX INITIALIZATION");
	if(!(e->win = mlx_new_window(e->mlx, e->height, e->width, title)))
		ft_putendl("ERROR CREATING WINDOW");
}

void	create_img(t_env *e)
{
	if (!(e->img = mlx_new_image(e->mlx, e->height, e->width)))
		ft_putendl("ERROR CREATING IMAGE");
	if(!(e->data = mlx_get_data_addr(e->img, &(e->bpp), &(e->sizeline), &(e->endian))))
		ft_putendl("ERROR OCCURED TO GET DATA ADDRESS");
}
