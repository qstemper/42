/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 11:37:35 by qstemper          #+#    #+#             */
/*   Updated: 2017/04/06 13:16:01 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <fcntl.h>
# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"

typedef struct	s_info
{
	int			numplayer;
	int			midmap;
	int			heightmap;
	int			weightmap;
	int			stopaggresive;
	int			cantplace;
	int			cantplacerl;
	int			finish;
	char		piece;
	char		**map;
}				t_info;

typedef struct	s_piece
{
	int			heightpiece;
	int			weightpiece;
	int			x;
	int			y;
	char		**piece;
}				t_piece;

/*
***			P2.C && PLAY_P2.C
*/

int				p2(t_info *info, t_piece *piece);
void			place_top_p2(t_info *info, t_piece *piece);
void			place_bot_p2(t_info *info, t_piece *piece);
void			place_right_p2(t_info *info, t_piece *piece);

/*
***			P1.C && PLAY_P1.C
*/

int				p1(t_info *info, t_piece *piece);
void			place_top_p1(t_info *info, t_piece *piece);
void			place_bot_p1(t_info *info, t_piece *piece);
void			place_left_p1(t_info *info, t_piece *piece);

/*
***			CHECK_PLACE.C && INFO.C
*/

int				check_place(t_info *info, t_piece *piece, int x, int y);
void			get_player(t_info *info);
void			assign_piece(t_info *info);
void			get_map_size(t_info *info);

/*
***			MAP_AND_PIECE.C
*/

void			get_piece(t_piece *piece);
void			get_map(t_info *info, t_piece *piece);
void			get_midmap(t_info *info);

#endif
