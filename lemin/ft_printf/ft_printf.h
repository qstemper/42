/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 13:11:10 by qstemper          #+#    #+#             */
/*   Updated: 2017/04/17 11:55:45 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include "headers/buff.h"
# include "headers/darray2.h"
# include "headers/darray.h"
# include "headers/header.h"
# include "headers/libft.h"
# include "headers/wide_char.h"

# define FMT format

# define SPECIAL_CSET "idDxXuUoOpsScC"
# define MODE_CSET "# +-0.hljz*"
# define UP_HEX_CSET "0123456789ABCDEF"
# define LOW_HEX_CSET "0123456789abcdef"

# define NB_SPECIAL_FUNCTION 15
# define NB_MODE_FUNCTION 12
# define NB_COLOR_ATTRIBUTE 20

# define ESCAPE_SEQ_SIZE 5
# define BUFF_SIZE 32
# define BUFF_COLOR_SIZE 1024

# define ALT 0x1
# define LADJUST 0x2
# define LONGINT 0x4
# define LLONGINT 0x8
# define SHORTINT 0x10
# define ZEROPAD 0x20
# define SIZET 0x40
# define INTMAXT 0x80
# define CHARINT 0x100

# define INTMAX_SIZE (INTMAXT|LLONGINT|SIZET)

# define COL_BLK 0x1
# define COL_RED 0x2
# define COL_GREE 0x4
# define COL_YEL 0x8
# define COL_BLU 0x10
# define COL_PIN 0x20
# define COL_CYA 0x40
# define COL_GRE 0x80
# define COL_DEF 0x100
# define COL_FBLK 0x200
# define COL_FRED 0x400
# define COL_FGREE 0x800
# define COL_FYEL 0x1000
# define COL_FBLU 0x2000
# define COL_FPIN 0x4000
# define COL_FCYA 0x8000
# define COL_FGRE 0x10000
# define COL_FDEF 0x20000
# define COL_GR 0x40000
# define COL_SS 0x80000
# define COL_SR 0x100000

typedef struct	s_printf_color
{
	char		*id;
	int			len;
	int			value;
	char		*attribute;
}				t_printf_color;

typedef struct	s_printf_mode
{
	int			flag;
	int			width;
	int			precision;
	int			special;
	char		sign;
	char		*xdigit;
	char		ox[2];
}				t_printf_mode;

typedef enum	e_printf_pad_char
{
	ZeroChar,
	BlankChar
}				t_printf_pad_char;

typedef int		(*t_printf_special_function)(t_printf_mode, va_list);
typedef int		(*t_printf_set_function)(t_printf_mode *, \
		const char *, va_list);

void			save_buff(void *buff, size_t size);

t_list			**buff_list(void);
t_printf_color	*col_attr(int i);

void			flush_fd(int fd);
void			flush_str(char *str);
void			flush_nstr(char *str, size_t size);

intmax_t		get_sj_arg(va_list ap, t_printf_mode mode);
long			get_s_arg(va_list ap, t_printf_mode mode);
uintmax_t		get_uj_arg(va_list ap, t_printf_mode mode);
t_ulong			get_u_arg(va_list ap, t_printf_mode mode);

int				get_special_index(char *cset, char c);
int				get_mode_index(char *cset, char c);

void			init_print(t_printf_special_function *print_format);
void			init_set(t_printf_set_function *set_mode);
void			init_color(t_printf_color *color);
void			init_color_i(t_printf_color *color, char *id, \
		int val, char *attribute);

char			*tool_ujtoa(uintmax_t val, int base, \
		t_printf_mode mode, char *cp);
char			*tool_ultoa(uintmax_t val, int base, \
		t_printf_mode mode, char *cp);

int				set_format_mode(const char *format, t_printf_mode *mode, \
		t_printf_set_function *set_mode, va_list ap);

int				set_space(t_printf_mode *mode);
int				set_plus(t_printf_mode *mode);
int				set_alt(t_printf_mode *mode);
int				set_minus(t_printf_mode *mode);
int				set_zero(t_printf_mode *mode);

int				set_h(t_printf_mode *mode);
int				set_l(t_printf_mode *mode);
int				set_j(t_printf_mode *mode);
int				set_z(t_printf_mode *mode);

void			set_color(int *color, const char *format);
int				set_precision(t_printf_mode *mode, \
		const char *format, va_list ap);
int				set_width(t_printf_mode *mode, const char *format);
int				set_aster(t_printf_mode *mode, const char *format, va_list ap);

int				color_flag(const char *format);
void			ft_printf_apply_color(const char *format);
void			ft_printf_write_color(int color);

int				print_d(t_printf_mode mode, va_list ap);
int				print_ld(t_printf_mode mode, va_list ap);
int				print_u(t_printf_mode mode, va_list ap);
int				print_lu(t_printf_mode mode, va_list ap);

int				print_x(t_printf_mode mode, va_list ap);
int				print_lx(t_printf_mode mode, va_list ap);
int				print_o(t_printf_mode mode, va_list ap);
int				print_lo(t_printf_mode mode, va_list ap);
int				print_p(t_printf_mode mode, va_list ap);

int				print_c(t_printf_mode mode, va_list ap);
int				print_lc(t_printf_mode mode, va_list ap);
int				print_s(t_printf_mode mode, va_list ap);
int				print_ls(t_printf_mode mode, va_list ap);
int				print_def(t_printf_mode mode);

int				ft_printf_dioux_val(uintmax_t ujval, t_ulong ulval, \
		int base, t_printf_mode mode);
int				ft_printf_p_val(uintmax_t ujval, t_printf_mode mode);
int				ft_printf_cs_val(char *cp, int size, t_printf_mode mode);

void			ft_printf_finaly_print(char *cp, int size, \
		int realsize, t_printf_mode mode);

int				ft_vlprintf(const char *format, va_list ap);

int				ft_vfprintf(int fd, const char *format, va_list ap);
int				ft_vsprintf(char *str, const char *format, va_list ap);
int				ft_vsnprintf(char *str, size_t size, \
		const char *format, va_list ap);

int				ft_printf(const char *format, ...);
int				ft_fprintf(int fd, const char *format, ...);
int				ft_sprintf(char *str, const char *format, ...);
int				ft_snprintf(char *str, size_t size, const char *format, ...);

#endif
