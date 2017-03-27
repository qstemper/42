#ifndef FILLER_H
# define FILLER_H

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

# define PRGM "filler"

# define O_DEBUG 0

typedef struct		s_filler
{
	int		exit;
	int		f;
	int		fd;
	int		mod;
	int		player;
	int		pchar;
	int		lpchar;
	int		smap_x;
	int		smap_y;
	int		me_x;
	int		me_y;
	int		vs_x;
	int		vs_y;
	int		spiece_x;
	int		spiece_y;
	int		put_x;
	int		put_y;
	char	**map;
	char	**piece;
}			t_filler;

/*
***			INIT_FILLER.C && FILLER_ERROR.C
*/

void			init_filler(t_filler *fill);
void			init_vm(t_filler *fill);
void			filler_error(int n);

/*
***			READ_PLAY.C && READ_MAP.C
*/

void			read_map(t_filler *fill);
void			read_play(t_filler *fill);

/*
***			PLAY.C && CHECK_PLAY.C
*/

void			play(t_filler *fill);
int				find_me(t_filler *fill, int y, float vs, float me);
int				check_play(t_filler *fill);

/*
***			TOP_PLAY.C
*/

void			top_play1(t_filler *fill, int mid_x, int mid_y);
void			top_play2(t_filler *fill, int mid_x, int mid_y);
void			top_play3(t_filler *fill, int mid_x, int mid_y);
void			top_play4(t_filler *fill, int mid_x, int mid_y);
void			top_play5(t_filler *fill, int mid_x, int mid_y);

/*
***			BOTTOM_PLAY.C
*/

void			bottom_play1(t_filler *fill, int mid_x, int mid_y);
void			bottom_play2(t_filler *fill, int mid_x, int mid_y);
void			bottom_play3(t_filler *fill, int mid_x, int mid_y);
void			bottom_play4(t_filler *fill, int mid_x, int mid_y);

/*
***			X_PLAY.X
*/

void			play_btlr(t_filler *fill);
void			play_btrl(t_filler *fill);
void			play_tblr(t_filler *fill);
void			play_tbrl(t_filler *fill);

/*
***			Y_PLAY.C
*/

void			play_tbrl_y(t_filler *fill);
void			play_tblr_y(t_filler *fill);
void			play_btrl_y(t_filler *fill);
void			play_btlr_y(t_filler *fill);

/*
***			PX_PLAY.C
*/

void			play_btlr_px(t_filler *fill, int y, int x);
void			play_btrl_px(t_filler *fill, int y, int x);
void			play_tblr_px(t_filler *fill, int y, int x);
void			play_tbrl_px(t_filler *fill, int y, int x);

/*
***			PY_PLAY.C
*/
void			play_tbrl_py(t_filler *fill, int y, int x);
void			play_tblr_py(t_filler *fill, int y, int x);
void			play_btrl_py(t_filler *fill, int y, int x);
void			play_btlr_py(t_filler *fill, int y, int x);

/*
***			SPLIT.C
*/

void			ft_strsplit_free(char ***split)
void			ft_strsplit_len(char ***split)

#endif
