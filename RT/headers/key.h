/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 08:58:59 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/18 09:07:15 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_H
# define KEY_H

# include <math.h>

# define K_ROT M_PI / 200
# define K_MOVE 0.045

typedef struct	s_key
{
	int			up;
	int			down;
	int			left;
	int			right;
	int			page_up;
	int			page_down;
	int			num_plus;
	int			num_minus;
	int			w;
	int			a;
	int			s;
	int			d;
	int			del;
	int			shift;
	int			ctrl;
	int			alt;
	int			tab;
	int			space;
}				t_key;

/*
***					key_init.c && key_check.c
*/

void			init_key(t_key *key);
int				is_key(t_key *key);
void			check_key(t_key);

/*
***					key_press.c && key_release.c
*/

int				keypress(int keycode, t_key *key);
int				keyrelease(int keycode, t_key);

#endif
