/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 10:48:02 by qstemper          #+#    #+#             */
/*   Updated: 2017/04/06 10:10:44 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <limits.h>
# include "get_next_line.h"
# include "libft.h"
# include "ft_printf.h"

# define CSET_O "dcvfn"
# define SIZE_O 5

# define O_DEBUG			0x1
# define O_COLOR			0x2
# define O_VERB				0x4
# define O_FIN				0x8
# define O_STROKE			0x10
# define O_PRIVATE_ERROR	0x20

# define FMT_U1 "%s: %s -- %c\n"
# define FMT_U2	"%s: %s [-%s] [%s]\n"
# define FMT_CU1 "{green|gr}%s{eoc}: {gr}%s{eoc} -- {red}%c{eoc}\n"
# define FMT_CU2 "{pink}%s{eoc}: {gr}%s{eoc} [{pink}-%s{eoc}] [{pink}%s{eoc}]\n"

# define CHECKSORT 100

# define IS(X, Y) ((Y & X) == X ? 1 : 0)

typedef struct	s_stackenv
{
	int			min;
	int			max;
	int			piv;
}				t_stackenv;

typedef struct	s_stack
{
	int			*tab;
	int			size;
}				t_stack;

typedef struct	s_ins
{
	char		*str;
	void		(*f)(t_stack *, t_stack *);
}				t_ins;

/*
***					GLOBAL_INS.C
*/

extern t_ins	g_ins[];

/*
***					ERROR.C
*/

int				error(int rtnvalue, int o);
int				usage(char *av, char c, int rtnvalue, int o);

/*
***					DEBUG.C
*/

void			debug(t_dlist *l, char *name, int o);
void			debug_split(void);
void			debug_o(int o);

/*
***					GETOPT.C
*/

int				get_opt(const char *cset, int ac, char **av, char *err);
int				go_over_opt(int ac, char **av);

/*
***					SIMPLE_OP.C
*/

void			op_sx(t_dlist **astack, int *stroke);
void			op_rx(t_dlist **astack, int *stroke);
void			op_rrx(t_dlist **astack, int *stroke);

/*
***					MULT_OP.C
*/

void			op_ss(t_dlist **astack_a, t_dlist **astack_b, int *stroke);
void			op_rs(t_dlist **astack_a, t_dlist **astack_b, int *stroke);
void			op_rrs(t_dlist **astack_a, t_dlist **astack_b, int *stroke);
void			op_px(t_dlist **astack_pop, t_dlist **astack_push, int *stroke);

/*
***					REVERSE.C
*/

int				reverse(t_dlist **astack, int o);
int				reverse_swap(t_dlist **astack, int o);

/*
***					NOSORT.C && SORT.C
*/

int				nosort(t_dlist *stack, int o, int finish);
void			sort(t_dlist **astack_a, t_dlist **astack_b, \
												size_t size, int o);

/*
***					ROLL.C
*/

int				reverse_roll(t_dlist **astack, int min, int o);
int				roll(t_dlist **astack, int min, int o);

/*
***					PUSHSWAP.C
*/

int				pushswap(int ac, char *av[], int o);

/*
***					MAIN.C
*/

t_stackenv		*stackenv(void);

/*
***					SWAP.C
*/

void			swap_a(t_stack *a, t_stack *b);
void			swap_b(t_stack *a, t_stack *b);
void			swap_both(t_stack *a, t_stack *b);

/*
***					PUSH.C
*/

void			push_a(t_stack *a, t_stack *b);
void			push_b(t_stack *a, t_stack *b);

/*
***					ROTATE.C
*/

void			rotate_a(t_stack *a, t_stack *b);
void			rotate_b(t_stack *a, t_stack *b);
void			rotate_both(t_stack *a, t_stack *b);

/*
***					REV_ROT.c
*/

void			rev_rot_a(t_stack *a, t_stack *b);
void			rev_rot_b(t_stack *a, t_stack *b);
void			rev_rot_both(t_stack *a, t_stack *b);

/*
***					TOOL.C
*/

int				check_arg(char **av);
void			destroy(t_stack a, t_stack b);

#endif
