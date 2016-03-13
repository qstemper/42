#include "fractol.h"

int	dragon(t_env *e, int i, t_p2d P, t_p2d Q)
{
	t_p2d	R;
	int	pos;

	if (i == 1)
	{
//		mlx_pixel_put(e->mlx, e->img, P.abs, P.ord, RED);
		pos = (e->x * e->bpp / 8) + (e->y * e->sizeline);
		e->data[pos] = (char)RED;
		e->data[pos + 1] = (char)GREEN;
		e->data[pos + 2] = (char)BLUE;
	}
	else
	{
		R.abs = (P.abs + Q.abs + Q.ord - P.ord) / 2;
		R.ord = (P.ord + Q.ord - Q.abs + P.abs) / 2;
		dragon(e, i - 1, P, R);
		dragon(e, i - 1, Q, R);
	}
	return (1);
}

int	launch_dragon(void *p)
{
	t_env	*e;
	t_p2d	A;
	t_p2d	B;

	e = (t_env *)p;
	e->n = 20;
	A.abs = 20;
	A.ord = 20;
	B.abs = 220;
	B.ord = 220;
	dragon(e, e->n, A, B);
	return (1);
}
	
