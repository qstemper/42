#include "frac.h"

void	init_frac(t_env *e)
{
	if (!(e->ftl_arr = (t_frac *)malloc(sizeof(t_frac) * 5)))
		error_malloc();
	e->ftl_ptr = NULL;
	e->ftl_arr[0] = (t_frac){{0, 0}, {0, 0}, -0.9, 0, 0, 0, 
		e->win_size_w / 2.7, e->win_size_h / 2.4,
		0.5, 0, 0, 50, mandelbrot};
	e->ftl_arr[1] = (t_frac){{0.285, 0.01}, {0, 0}, 0, 0, 0, 0, 
		e->win_size_w / 3.0, e->win_size_h / 2.4,
		0.5, 0, 0, 10, julia};
	e->ftl_arr[2] = (t_frac){{0, 0}, {0, 0}, -2.1, 0.6, -1.2, 1.2, 
		e->win_size_w / 2.7, e->win_size_h / 2.4,
		1, 0, 0, 50, carpet};
	e->ftl_arr[3] = (t_frac){{0, 0}, {0, 0}, 0, 0, 0, 0, 
		e->win_size_w / 2.7, e->win_size_h / 2.4,
		0.5, 0, 0, 50, b_ship};
	e->ftl_arr[4] = (t_frac){{0, 0}, {0, 0}, 0, 0, 0, 0, 
		e->win_size_w / 2.7, e->win_size_h / 2.4,
		0.5, 0, 0, 50, mandelbar};
	e->ftl_ptr = &(e->ftl_arr[0]);
}

int	mandelbrot(t_env *e, t_frac ftl, t_point *pt)
{
	ftl.c.r = 1.0 * (pt->x - e->win_size_w / 2) /
		(0.5 * ftl.zoom_ratio * e->win_size_w) + ftl.x1;
	ftl.c.im = (pt->y - e->win_size_h / 2) /
		(0.5 * ftl.zoom_ratio * e->win_size_h) + ftl.y1;
	while ((ftl.z.r * ftl.z.r + ftl.z.im * ftl.z.im < 4) \
				&& (ftl.ite < ftl.ite_max))
	{
		ftl.tmp = ftl.z.r;
		ftl.z.r = ftl.z.r * ftl.z.r - ftl.z.im * ftl.z.im + ftl.c.r;
		ftl.z.im = 2 * ftl.z.im * ftl.tmp + ftl.c.im;
		ftl.ite += 1;
	}
	if (ftl.ite == ftl.ite_max)
		return (get_color(100, *(e->p_col_ptr)));
	return (get_color((ftl.ite * ftl.ite) * 0.1, *(e->p_col_ptr)));
}

int	mandelbar(t_env *e, t_frac ftl, t_point *pt)
{
	ftl.c.r = 1.0 * (pt->x - e->win_size_w / 2) /
		(0.5 * ftl.zoom_ratio * e->win_size_w) + ftl.x1;
	ftl.c.im = (pt->y - e->win_size_h / 2) /
		(0.5 * ftl.zoom_ratio * e->win_size_h) + ftl.y1;
	while ((ftl.z.r * ftl.z.r + ftl.z.im * ftl.z.im < 4) \
				&& (ftl.ite < ftl.ite_max))
	{
		ftl.tmp = ftl.z.r;
		ftl.z.im *= -1;
		ftl.z.r = ftl.z.r * ftl.z.r - ftl.z.im * ftl.z.im + ftl.c.r;
		ftl.z.im = 2 * ftl.z.im * ftl.tmp + ftl.c.im;
		ftl.ite += 1;
	}
	if (ftl.ite == ftl.ite_max)
		return (get_color(100, *(e->p_col_ptr)));
	return (get_color((ftl.ite * ftl.ite) * 0.1, *(e->p_col_ptr)));
}

int	julia(t_env *e, t_frac ftl, t_point *pt)
{
	ftl.z.r = 1.0 * (pt->x - e->win_size_w / 2) /
		(0.5 * ftl.zoom_ratio * e->win_size_w) + ftl.x1;
	ftl.z.im = (pt->y - e->win_size_h / 2) /
		(0.5 * ftl.zoom_ratio * e->win_size_h) + ftl.y1;
	while ((ftl.z.r * ftl.z.r + ftl.z.im * ftl.z.im < 4) \
				&& (ftl.ite < ftl.ite_max))
	{
		ftl.tmp = ftl.z.r;
		ftl.z.r = ftl.z.r * ftl.z.r - ftl.z.im * ftl.z.im + ftl.c.r;
		ftl.z.im = 2 * ftl.z.im * ftl.tmp + ftl.c.im;
		ftl.ite += 1;
	}
	if (ftl.ite == ftl.ite_max)
		return (get_color(100, *(e->p_col_ptr)));
	return (get_color((ftl.ite * ftl.ite) * 0.1, *(e->p_col_ptr)));
}

int	b_ship(t_env *e, t_frac ftl, t_point *pt)
{
	(void)e;
	ftl.c.r = 1.0 * (pt->x - e->win_size_w / 2) /
		(0.5 * ftl.zoom_ratio * e->win_size_w) + ftl.x1;
	ftl.c.im = (pt->y - e->win_size_h / 2) /
		(0.5 * ftl.zoom_ratio * e->win_size_h) + ftl.y1;
	while ((ftl.z.r * ftl.z.r + ftl.z.im * ftl.z.im < 4) \
				&& (ftl.ite < ftl.ite_max))
	{
		ftl.tmp = ftl.z.r;
		ftl.z.r = ftl.z.r * ftl.z.r - ftl.z.im * ftl.z.im + ftl.c.r;
		ftl.z.im = 2 * fabs(ftl.z.im) * fabs(ftl.tmp) + ftl.c.im;
		ftl.ite += 1;
	}
	if (ftl.ite == ftl.ite_max)
		return (rgb_creating(ftl.ite * 255 / ftl.ite_max, 10 , 0));
	return (rgb_creating(ftl.ite * 255 / ftl.ite_max, ftl.ite * 255 / (ftl.ite_max * 2), 0));
}
