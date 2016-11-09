/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 10:50:39 by qstemper          #+#    #+#             */
/*   Updated: 2016/11/08 10:38:57 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		exist_cmd(char **env, char **tab, t_termios term_orig)
{
	char		*str;
	int			ac;

	ac = -1;
	while (tab[++ac])
		;
	str = tab[0];
	if (ft_strcmp(str, ECHO) == 0)
		builtin_echo(ac, tab);
	else if (ft_strcmp(str, EXIT) == 0)
		builtin_exit(term_orig);
	else if (ft_strcmp(str, CD) == 0)
		builtin_cd(ac, tab, env);
	else if (ft_strcmp(str, ENV) == 0)
		builtin_env(ac, tab, env, term_orig);
	else if (ft_strcmp(str, SET_E) == 0)
		builtin_setenv(ac, tab, env, term_orig);
	else if (ft_strcmp(str, UNSET_E) == 0)
		builtin_unsetenv(ac, tab, env);
}

static char		**pars_path(char **tab_path, char **env, t_termios term_orig)
{
	char		*str;

	str = get_env(env, "PATH", term_orig);
	if (!(tab_path = ft_strsplit(str, ':')))
		error_pars("ERROR_PARS");
	return (tab_path);
}

char			*pars(char *str, char **env, int term_orig)
{
	char		**tab;
	char		**tab_path;
	DIR			*dir;
	t_dirent	*entry;
	int			i;

	tab = NULL;
	if (!(tab = ft_strsplit(str, ' ')))
		error_pars("ERROR_PARS", term_orig);
	exist_cmd(env, tab, term_orig);
	tab_path = pars_path(tab_path, env, term_orig);
	i = -1;
	while (tab_path[++i])
	{
		dir = opendir(tab[i]);
		if (!dir)
			continue ;
		while ((entry = readdir(dir)))
/*
***
*/
		closedir(dir);
	}
	return (str);
}
