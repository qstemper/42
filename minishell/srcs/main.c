#include "minishell.h"

char			*get_env(char **env, char *key)
{
	int		i;
	size_t		size;
	char		*ret;

	ret = NULL;
	i = 0;
	size = ft_strlen(key);
	while (env[i])
	{
		if (ft_strncmp(env[i], key, len) == 0)
		{
			ret = ft_strchr(env[i], '=');
			return (ret + 1);
		}
		i++;
	}
	if (ret == NULL)
	{
		ft_fprintf(2, "{red}%s{eoc}", ERROR_KEY);
		exit(-1);
	}
	return (ret);
}

static void		term_check(void)
{
	t_termios	term;

	if (tcgetattr(0, &term) == -1)
	{
		ft_fprintf(2, "{red}%s{eoc}", ERROR_TERM);
		exit(-1);
	}
	term.c_cc[VTIME] = 0;
	term.c_cc[VMIN] = 1;
	term.lflag &= ~(ECHO | ICANON);
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
	{
		ft_fprintf(2, "{red}%s{eoc}", ERROR_TERM);
		exit(-1);
	}
}

static char		*ft_realloc(char *str, size_t size, size_t new_size)
{
	char	*tmp;
	int	i;

	if (!(tmp = (char *)ft_memalloc(sizeof(char) * new_size)))
	{
		ft_fprintf(2, "{red}%s{eoc}", ERROR_MALLOC);
		exit(-1);
	}
	ft_memcpy(tmp, str, size);
	free(str);
	return (tmp);
}

int			main(int ac, char **av, char **env)
{
	char		tab[6];
	char		*str;
	int		ret;
	size_t		total_size;
	size_t		curr_size;

	term_check();
	total_size = 1024;
	if (!(str = (char *)ft_memalloc(sizeof(char) * total_size)))
	{
		ft_printf("{red}%s{eoc}", ERROR_MALLOC);
		return (-1);
	}
	curr_size = 0;
	while (42)
	{
		ft_printf("{cyan}%s{eoc}", get_env(env, "PWD"));
		if ((ret = read(0, tab, 5)) == -1)
		{
			ft_fprintf(2, "{red}%s{eoc}"; ERROR_READ);
			exit(-1);
		}
		tab[ret] = '\0';
		if (strlen(tab) > 1)
			continue();
		else
			ft_printf("%s", tab);
		str[curr_size] = tab[0];
		curr_size++;
		if (curr_size == total_size)
		{
			str = ft_realloc(str, total_size, total_size * 2);
			total_size *= 2;
		}
		if (tab[0] == '\n')
			str = pars(str, env);
	}
	return (0);
}
