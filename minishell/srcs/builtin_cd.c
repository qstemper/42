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

void		builtin_cd(int ac, char **tab, char **env, t_termios term_orig)
{
	int		opt;
	int		skip;
	int		e;
	char	*abs_path;

	e = 0;
	opt = get_opt(CHARSET_CD, ac, tab, &e);
	skip = skip(ac, tab);
	if (IS(ERROR_BUILTIN_OPT, opt))
		error_builtin("ERROR_ATTR");
	check_home(ac, env, term_orig);
	check_pwd(ac, env, term_orig);
	e = check_oldpwd(env);
}
