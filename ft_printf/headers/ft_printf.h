#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include "ft_wchar.h"

# define FMT format

# define SPEC_CSER "idDxXuUoOpsScC"
# define MOD_CSET "# +-0.ljz"
# define UP_HEX_CSET "0123456789ABCDEF"
# define LOW_HEX_CSET "0123456789abcdef"

# define NB_SPEC_FUNCTION 15
# define NB_MOD_FUNCTION 12
# define NB_COLOR_ATTRIB 20

# define ESCAPE_SEQ_SIZE 5
# define SIZE_BUFF 32
# define BUF_COLOR_SIZE 1024

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

# define COL_BLANK 0x1
# define COL_RED 0x2
# define COL_GREEN 0x4
# define COL_YELLOW 0x8
# define COL_BLUE 0x10
# define COL_PINK 0x20
# define COL_CYAN 0x40
# define COL_GREY 0x80
# define COL_DEFAULT 0x100
# define COL_FBLANK 0x200
# define COL_FRED 0x400
# define COL_FGREEN 0x800
# define COL_FYELLOW 0x1000
# define COL_FBLUE 0x2000
# define COL_FPINK 0x4000
# define COL_FCYAN 0x8000
# define COL_FGREY 0x10000
# define COL_FDEFAULT 0x20000
# define COL_GR 0x40000
# define COL_SS 0x80000
# define COL_SR 0x100000

typedef struct	s_printf_color
{
	char		*id;
	int			length;
	int			value;
	char		*attribute;
}				t_printf_color;

typedef struct	s_printf_mod
{
	int			flag;
	int			width;
	int			prec;
	int			spec;
	char		sign;
	char		*xdigit;
	char		ox[2];
}				t_printf_mod;

typedef enum	e_printf_pad_char
{
	ZeroChar,
	BlankChar
}				t_printf_pad_char;

typedef int		(*t_printf_spec_function)(t_printf_mod, va_list);
typedef int		(*t_printf_spec_function)(t_printf_mod *, const char *, va_list);

void			save_buff(void *buff, size_t size);

t_list			**buff_list(void);
t_printf_color	*color_attribute(int i);

void			flush_fd(int fd);
void			flush_str(char *str);
void			flush_nstr(char *str, size_t size);

intmax_t		get_sj_arg(va_list ap, t_printf_mod mod);
long			get_s_arg(va_list ap, t_printf_mod mod);
uintmax_t		get_uj_arg(va_list ap, t_printf_mod mod);
intmax_t		get_u_arg(va_list ap, t_printf_mod mod);

int				get_spec_index(char *cset, char c);
int				get_mod_index(char *cset, char c);

void			init_print(t_printf_spec_function *print_format);
void			init_set(t_printf_spec_function *set_mod);
void			init_color(t_printf_color *color);
void			init_color_i(t_printf_color *color, char *id, int val, char *attribute);

char			*tool_ujtoa(uintmax_t val, int base, t_printf_mod mod, char *cp);
char			*tool_ultoa(uintmax_t val, int base, t_printf_mod mod, char *cp);

int				set_format_mod(const char *format, t_printf_mod *mod, t_printf_set_function *set_mod, va_list ap);

int				set_space(t_printf_mod *mod);
int				set_plus(t_printf_mod *mod);
int				set_alt(t_printf_mod *mod);
int				set_minus(t_printf_mod *mod);
int				set_zero(t_printf_mod *mod);

int				set_h(t_printf_mod *mod);
int				set_l(t_printf_mod *mod);
int				set_j(t_printf_mod *mod);
int				set_z(t_printf_mod *mod);

void			set_color(int *color, const char *format);
void			ft_printf_apply_color(const char *format);
void			ft_printf_write_color(int color);

int				print_d(t_printf_mod mod, va_list ap);
int				print_ld(t_printf_mod mod, va_list ap);
int				print_u(t_printf_mod mod, va_list ap);
int				print_lu(t_printf_mod mod, va_list ap);

int				print_x(t_printf_mod mod, va_list ap);
int				print_lx(t_printf_mod mod, va_list ap);
int				print_o(t_printf_mod mod, va_list ap);
int				print_lo(t_printf_mod mod, va_list ap);
int				print_p(t_printf_mod mod, va_list ap);


int				print_c(t_printf_mod mod, va_list ap);
int				print_lc(t_printf_mod mod, va_list ap);
int				print_s(t_printf_mod mod, va_list ap);
int				print_ls(t_printf_mod mod, va_list ap);
int				print_def(t_printf_mod mod);

int				ft_printf_diuox_val(uintmax_t ujval, t_ulong ulval, int base, t_printf_mod mod);
int				ft_printf_p_val(uintmax_t ujval, t_printf_mod mod);
int				ft_printf_cs_val(char *cp, int size, t_printf_mod mod);

void			ft_printf_finaly_print(char *cp, int size, int realsize, t_printf_mod mod);

int				ft_vlprintf(const char *format, va_list ap):

int				ft_vfprintf(int fd, const char *format, va_list ap);
int				ft_vsprintf(char *str, const char *format, va_list ap);
int				ft_vsnprintf(char *str, size_t size, const char *format, va_list ap);

int				ft_printf(const char *format, ...);
int				ft_fprintf(int fd, const char *format, ...);
int				ft_sprintf(char *str, const char *format, ...);
int				ft_snprintf(char *str, size_t size, const char *format, ...);

#endif
