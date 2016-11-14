/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 07:38:48 by qstemper          #+#    #+#             */
/*   Updated: 2016/11/08 09:05:14 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*cons_abs_path(char **env, char *str, t_termios term_orig)
{
	char	*abs_path;
	char	**tab;
	int		len;

	tab = NULL;
	abs_path = NULL;
	len = 0;
	if ((tab = ft_strsplit(str, '/')) == NULL)
		error("ERROR_MALLOC", term_orig);
	while (*tab)
	{
		len += ft_strlen(*tab);
		tab++;
	}
	if (!(abs_path = (char *)ft_memalloc(sizeof(char) * (len + 1))))
		error("ERROR_MALLOC", term_orig);
	conv_tilde(env, &abs_path, tab);
	conv_point(&abs_path, tab);
}

void		builtin_cd(int ac, char **tab, char **env, t_termios term_orig)
{
	int		opt;
	int		skip;
	int		e;

	e = 0;
	opt = get_opt(CHARSET_CD, ac, tab, &e);
	skip = skip(ac, tab);
	if (IS(ERROR_BUILTIN_OPT, opt))
		error_builtin("ERROR_ATTR");
	check_home(ac, env, term_orig);
	check_pwd(ac, env, term_orig);
	e = check_oldpwd(env);
	cons_abs_path(env, tab[skip], term_orig);
}
