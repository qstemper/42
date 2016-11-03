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

static t_termios	term_check(void)
{
	t_termios		term;
	t_termios		term2;

	if (tcgetattr(0, &term) == -1)
		error("ERROR_TERM");
	term2 = term;
	term.c_cc[VTIME] = 0;
	term.c_cc[VMIN] = 1;
	term.lflag &= ~(ECHO | ICANON);
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		error("ERROR_TERM");
	return (term2);
}

static char			*ft_realloc(char *str, size_t size, size_t new_size, \
	t_termios term_orig)
{
	char			*tmp;
	int				i;

	if (!(tmp = (char *)ft_memalloc(sizeof(char) * new_size)))
		error("ERROR_MALLOC", term_orig);
	ft_memcpy(tmp, str, size);
	free(str);
	return (tmp);
}

static int			read_error(t_termios term_orig)
{
	int				ret;

	if ((ret = read(0, tab, 5)) == -1)
		error("ERROR_READ", term_orig);
	return (ret);
}

static void			minishell(char *str, int total_size, t_termios term_orig, \
	char **env)
{
	size_t			curr_size;
	int				ret;
	char			tab[6];

	curr_size = 0;
	while (42)
	{
		ft_printf("{cyan}%s $>{eoc}", get_env(env, "PWD", term_orig));
		ret = read_error(term_orig);
		tab[ret] = '\0';
		if (ft_strlen(tab) > 1)
			continue();
		else
			ft_printf("%s", tab);
		str[curr_size] = tab[0];
		curr_size++;
		if (curr_size == total_size)
		{
			str = ft_realloc(str, curr_size, total_size * 2, term_orig);
			total_size *= 2;
		}
		if (tab[0] == '\n')
			str = pars(str, env, term_orig);
	}
}

int					main(int ac, char **av, char **env)
{
	char			*str;
	t_termios		term_orig;

	term_orig = term_check();
	total_size = 1024;
	if (!(str = (char *)ft_memalloc(sizeof(char) * total_size)))
		error("ERROR_MALLOC", term_orig);
	minishell(str, total_size, term_orig, env);
	return (0);
}
