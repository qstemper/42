#ifndef FRACTOL_H

# define FRACTOL_H

# include "libft.h"
# include "libmath.h"
# include <mlx.h>
# include <unistd.h>

# define ite_max 50
# define zoom 100
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
#define BLACK 0x000000

typedef struct	s_cplx
{
	float	r;
	float	im;
}		t_cplx;

typedef struct s_env
{
	void	*mlx;
	void	*win;
	void	*img;
}		t_env;

void	mandelbrot(float x, float y);

#endif
