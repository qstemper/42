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

#include "minishell.h"

static int	check_home(char **env)
{
	int		skip;
	int		i;
	char	**str;

	skip = skip_opt(ac, tab);
	i = -1;
	str = NULL;
	while (env[++i])
	{
		if (ft_strcmp(env[i], "HOME="))
			break ;
	}
	if ((str = ft_strsplit(env[i], '=')) == NULL || \
			str[0] == NULL || str[1] == NULL)
		return (1);
	return (0);
}

void		builtin_cd(int ac, char **tab, char **env)
{
	int		opt;
	int		skip;
	int		err;
	pid_t	pid;

	e = 0;
	opt = get_opt(CHARSER_CD, ac, tab, &err);
	skip = skip(ac, tab);
	pid = fork();
	if (IS(ERROR_BUILTINT_OPT, opt))
		error_builtin("ERROR_ATTR");
	if (tab[skip + 1] != '\0')
		error_usage(4);
	if ((err = check_home(env)) == 1)
		error("ERROR_CD_HOME");
} 
