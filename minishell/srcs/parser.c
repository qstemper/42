/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 10:50:39 by qstemper          #+#    #+#             */
/*   Updated: 2016/11/01 16:52:54 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		exist_cmd(char **env, char **tab)
{
	char		*str;

	str = tab[0];
	if (ft_strcmp(str, ECHO) == 0)
		builtin_echo(tab);
	else if (ft_strcmp(str, CD) == 0)
		builtin_cd(env, tab);
	else if (ft_strcmp(str, EXIT) == 0)
		builtin_exit();
	else if (ft_strcmp(str, ENV) == 0)
		builtin_env(env, tab);
	else if (ft_strcmp(str, SET_E) == 0)
		builtin_setenv(tab);
	else if (ft_strcmp(str, UNSET_E) == 0)
		builtin_unsetenv(tab);
	}

static char		**pars_path(char **tab_path, char **env)
{
	char		*str;

	str = get_env(env, "PATH");
	if (!(tab_path = ft_strsplit(str, ':')))
		error("ERROR_PARS");
	return (tab_path);
}

char			*pars(char *str, char **env)
{
	char		**tab;
	char		**tab_path;
	DIR			*dir;
	t_dirent	*entry;
	int			i;

	tab = NULL;
	if (!(tab = ft_strsplit(str, ' ')))
		error("ERROR_PARS");
	tab_path = pars_path(tab_path, env);
	exist_cmd(env, tab);
	i = -1;
	while (tab_path[++i])
	{
		dir = opendir(tab[i]);
		if (!dir)
			continue ;
		while ((entry = readdir(dir)))
			
		closedir(dir);
	}
	return (str);
}
