/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 10:50:43 by qstemper          #+#    #+#             */
/*   Updated: 2016/11/01 16:53:52 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void		term_check(void)
{
	t_termios	term;

	if (tcgetattr(0, &term) == -1)
		error("ERROR_TERM");
	term.c_cc[VTIME] = 0;
	term.c_cc[VMIN] = 1;
	term.lflag &= ~(ECHO | ICANON);
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		error("ERROR_TERM");
}

static char		*ft_realloc(char *str, size_t size, size_t new_size)
{
	char		*tmp;
	int			i;

	if (!(tmp = (char *)ft_memalloc(sizeof(char) * new_size)))
		error("ERROR_MALLOC");
	ft_memcpy(tmp, str, size);
	free(str);
	return (tmp);
}

static int		read_error()
{
	int			ret;

	if ((ret = read(0, tab, 5)) == -1)
		error("ERROR_READ");
	return (ret);
}

static void		minishell(char *str, int total_size)
{
	size_t		curr_size;
	int			ret;
	char		tab[6];

	curr_size = 0;
	while (42)
	{
		ft_printf("{cyan}%s{eoc}", get_env(env, "PWD"));
		ret = read_error();
		tab[ret] = '\0';
		if (ft_strlen(tab) > 1)
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
}

int				main(int ac, char **av, char **env)
{
	char		*str;
	size_t		total_size;

	term_check();
	total_size = 1024;
	if (!(str = (char *)ft_memalloc(sizeof(char) * total_size)))
		error("ERROR_MALLOC");
	minishell(str, total_size);

	return (0);
}
