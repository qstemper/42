#include "ft_printf.h"

static void	color_attribute_copy(char *buff, int color)
{
	int		i;

	i = -1;
	while (color && ++i < NB_COLOR_ATTRIBUTE)
	{
		if (color_attribute(i)->value & color)
		{
			ft_memcpy(buff, color_attribute(i)->attribute, ft_strlen(color_attribute(i)->attribute));
			buff += ft_strlen(color_attribute(i)->attribute);
			color &= ~color_attribute(i)->value;
			if (color)
					ft_memcpy(buff++, ";", 1);
		}
	}
	ft_memcpy(buff, "m\0", 2);
}

void		ft_printf_write_color(int color)
{
	char	buff[BUFF_COLOR_SIZE];
	char	*cp;

	ft_bzero((void *)buff, BUFF_COLOR_SIZE);
	cp = buff;
	ft_memcpy(cp, "\033[", 2);
	cp += 2;
	if (!color)
			color |= COL_DEFAULT;
	color_attribute_copy(cp, color);
	save_buff(buff, ft_strlen(buff));
}

int			color_flag(const char *format)
{
	int		flag;
	int		i;

	flag = 0;
	while (*format && *format != '}')
	{
		i = -1;
		if (*format == '|')
				format++;
		else
		{
			while (++i < NB_COLOR_ATTRIBUTE)
			{
				if (!ft_strncmp(format, color_attribute(i)->id, color_attribute(i)->length))
				{
					flag |= color_attribute(i)->value;
					format += color_attribute(i)->length;
					break ;
				}
			}
		}
		if (i == NB_COLOR_ATTRIBUTE)
				break ;
	}
	return (flag);
}

void		ft_printf_apply_color(const char *format)
{
		int	color;

		color = 0;
		set_color(&color, format);
		ft_printf_write_color(color);
}
