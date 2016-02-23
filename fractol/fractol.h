#ifndef FRACTOL_H

# define FRACTOL_H

# include "headers/libft.h"
# include "headers/libmath.h"
# include <mlx.h>
# include <unistd.h>

# define zoom 150
# define x_min -2.1
# define x_max 0.6
# define y_min -1.2
# define y_max 1.2
# define img_x (x_max - x_min) * zoom
# define img_y (y_max - y_min) * zoom
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define WHITE 0xFFFFFF
# define BLACK 0x000000

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	int	*img;
	char	*data;
	int	bpp;
	int	sizeline;
	int	endian;
	float	x;
	float	y;
	int	n;
	int	dx;
	int	dy;
	int	pix_nb;
}		t_env;

typedef struct	s_point
{
	int	abs;
	int	ord;
}		t_p2d;

int	mandelbrot(void *p);
int	julia(void *p);
int	launch_dragon(void *p);
int	dragon(t_env *e, int i, t_p2d P, t_p2d Q);

#endif
