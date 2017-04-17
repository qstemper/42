/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 03:06:27 by qstemper          #+#    #+#             */
/*   Updated: 2017/04/17 11:48:37 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_print(t_printf_special_function *print_format)
{
	print_format[0] = print_d;
	print_format[1] = print_d;
	print_format[2] = print_ld;
	print_format[3] = print_x;
	print_format[4] = print_lx;
	print_format[5] = print_u;
	print_format[6] = print_lu;
	print_format[7] = print_o;
	print_format[8] = print_lo;
	print_format[9] = print_p;
	print_format[10] = print_s;
	print_format[11] = print_ls;
	print_format[12] = print_c;
	print_format[13] = print_ls;
	print_format[14] = (t_printf_special_function)print_def;
}

void	init_set(t_printf_set_function *set_mode)
{
	set_mode[0] = (t_printf_set_function)set_alt;
	set_mode[1] = (t_printf_set_function)set_space;
	set_mode[2] = (t_printf_set_function)set_plus;
	set_mode[3] = (t_printf_set_function)set_minus;
	set_mode[4] = (t_printf_set_function)set_zero;
	set_mode[5] = set_precision;
	set_mode[6] = (t_printf_set_function)set_h;
	set_mode[7] = (t_printf_set_function)set_l;
	set_mode[8] = (t_printf_set_function)set_j;
	set_mode[9] = (t_printf_set_function)set_z;
	set_mode[10] = set_aster;
	set_mode[11] = (t_printf_set_function)set_width;
}

void	init_color_i(t_printf_color *color, char *id, int value, \
		char *attribute)
{
	color->id = id;
	color->value = value;
	color->len = ft_strlen(id);
	color->attribute = attribute;
}

void	init_color(t_printf_color *color)
{
	init_color_i(color, "blank", COL_BLK, "30");
	init_color_i(color + 1, "red", COL_RED, "31");
	init_color_i(color + 2, "green", COL_GREE, "32");
	init_color_i(color + 3, "yellow", COL_YEL, "33");
	init_color_i(color + 4, "blue", COL_BLU, "34");
	init_color_i(color + 5, "pink", COL_PIN, "35");
	init_color_i(color + 6, "cyan", COL_CYA, "36");
	init_color_i(color + 7, "grey", COL_GRE, "37");
	init_color_i(color + 8, "eoc", COL_DEF, "0");
	init_color_i(color + 9, "font-blank", COL_FBLK, "40");
	init_color_i(color + 10, "font-red", COL_FRED, "41");
	init_color_i(color + 11, "font-green", COL_FGREE, "42");
	init_color_i(color + 12, "font-yellow", COL_FYEL, "43");
	init_color_i(color + 13, "font-blue", COL_FBLU, "44");
	init_color_i(color + 14, "font-pink", COL_FPIN, "45");
	init_color_i(color + 15, "font-cyan", COL_FCYA, "46");
	init_color_i(color + 16, "font-grey", COL_FGRE, "47");
	init_color_i(color + 17, "fat", COL_GR, "1");
	init_color_i(color + 18, "underline", COL_SS, "4");
	init_color_i(color + 19, "highlight", COL_SR, "7");
}
