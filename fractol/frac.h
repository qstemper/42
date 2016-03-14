#ifndef FRAC_H

# define FRAC_H

# include "headers/libft.h"
# include <mlx.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>

# define FREE(x) {if (x) free(x); x = NULL;}
# define FREE_ARR(x) {if (x && *x) ft_arrfree(&x);}

# define WINDOW_SIZE_H 729
# define WINDOW_SIZE_W 729
# define ITE_MAX 50

# define KEY_ESC 53

# define KEY_MOUSE_CLIC_L 1
# define KEY_MOUSE_CLIC_R 2
# define KEY_MOUSE_UP 5
# define KEY_MOUSE_DOWN 4
# define KEY_MOUSE_LEFT 7
# define KEY_MOUSE_RIGHT 6

# define KEY_0 29
# define KEY_1 18
# define KEY_2 19
# define KEY_3 20
# define KEY_4 21
# define KEY_5 23
# define KEY_6 22
# define KEY_7 26
# define KEY_8 28
# define KEY_9 25

# define KEY_KP_DOT 65
# define KEY_KP_ENTER 76
# define KEY_KP_0 82
# define KEY_KP_1 83
# define KEY_KP_2 84
# define KEY_KP_3 85
# define KEY_KP_4 86
# define KEY_KP_5 87
# define KEY_KP_6 88
# define KEY_KP_7 89
# define KEY_KP_8 91
# define KEY_KP_9 92
# define KEY_KP_MINUS 69
# define KEY_KP_PLUS 78

# define KEY_PAGE_UP 116
# define KEY_PAGE_DOWN 121

# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124

# define PTR_MOTION_MASK (1L<<6)
# define MOTION_NOTIFY 6
# define KEY_PRESS_MASK (1L<<0)
# define KEY_PRESS 2

typedef struct	s_point
{
	float	x;
	float	y;
}		t_point;

typedef struct	s_cplx
{
	float	r;
	float	im;
}		t_cplx;

typedef struct	s_palette
{
	int	col_def;
	int	col_0;
	int	col_1;
	int	col_2;
	int	col_3;
	int	col_4;
	int	col_5;
	int	col_6;
	int	col_7;
	int	col_8;
	int	col_9;
}		t_pal;

typedef struct	s_frac
{
	t_cplx	c;
	t_cplx	z;
	float	x1;
	float	x2;
	float	y1;
	float	y2;
	float	zoom_x;
	float	zoom_y;
	float	zoom_ratio;
	float	tmp;
	int	ite;
	int	ite_max;
	void	*func;
}		t_frac;

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*pixel_img;
	int	bpp;
	int	sizeline;
	int	endian;
	int	win_size_h;
	int	win_size_w;
	int	stop_motion;
	t_frac	*ftl_ptr;
	t_frac	*ftl_arr;
	t_pal	*p_col_ptr;
	t_pal	*p_col_arr;
}		t_env;

void		ft_exit(void);
void		ft_malloc_error(void);
void		ft_error_str(char *str);
void		ft_error_str_exit(char *str);

void		ftl_draw_win(char *title, t_env *e);
void		ftl_draw_pixel_img(t_point *point, t_env *e, int col);
void		ftl_draw_reload(t_env *e);

int		ftl_mouse_hook(int button, int x, int y, t_env *e);
int		ftl_motion_hook(int x, int y, t_env *e);
int		ftl_key_hook(int keycode, t_env *e);

void		ftl_cal_apply(t_env *e, t_frac *ftl, int (*f)(t_env *e, t_frac, t_point*));

void		ftl_frac_init(t_env *e);
int		ftl_frac_mandelbrot(t_env *e, t_frac ftl, t_point *point);
int		ftl_frac_julia(t_env *e, t_frac ftl, t_point *point);
int		ftl_frac_mandelbar(t_env *e, t_frac ftl, t_point *point);
int		ftl_frac_b_ship(t_env *e, t_frac ftl, t_point *point);

int		ftl_frac_carpet(t_env *e, t_frac ftl, t_point *point);

int		ftl_create_rgb(int r, int g, int b);
void		ftl_change_frac(char *name_ftl, t_env *e);
void		ftl_key_hook_change_frac(int keycode, t_env *e);
void		ftl_key_hook_change_col(int keycode, t_env *e);

void		ftl_col_init(t_env *e);
void		ftl_col_change(int num, t_env *e);
int		ftl_get_col(int z, t_pal pal);

#endif
