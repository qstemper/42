/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_ins.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 11:25:00 by qstemper          #+#    #+#             */
/*   Updated: 2017/03/22 15:14:40 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_ins		g_ins[] = {\
	{"sa", swap_a}, \
	{"sb", swap_b}, \
	{"ss", swap_both}, \
	{"pa", push_a}, \
	{"pb", push_b}, \
	{"ra", rotate_a}, \
	{"rb", rotate_b}, \
	{"rr", rotate_both}, \
	{"rra", rev_rot_a}, \
	{"rrb", rev_rot_b}, \
	{"rrr", rev_rot_both} \
};
