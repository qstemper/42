/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 10:54:43 by qstemper          #+#    #+#             */
/*   Updated: 2016/11/08 08:30:52 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int			skip_opt(int ac, char **tab)
{
	int		i;

	i = 0;
	while (++i < ac)
	{
		if ((av[i][0] != '-') || (ft_strlen(av[i]) == 1))
			break ;
	}
	return (i);
}

static int	get_solo_opt(const char *charset, char c, char *e)
{
	int		o;

	o = 0x1;
	while (*charset)
	{
		if (*charset++ == c)
			return (o);
		o <<= 0x1;
	}
	if (!*e)
		*e = c;
	return (ERROR_BUILTIN_OPT);
}

int			get_opt(const char *cset, int ac, char **av, char *err)
{
	int		i;
	int		j;
	int		o;

	i = 0;
	o = 0x0;
	while (++i < ac)
	{
		if ((av[i][0] != '-') || (ft_strlen(av[i]) == 1))
			break ;
		j = 0;
		while (av[i][++j])
			o |= get_solo_opt(cset, av[i][j], err);
	}
	return (o);
}

int				is_env(char **env, char *key)
{
	int			i;

	i = -1;
	while (env[++i])
	{
		if (ft_strcmp(env[i], key) == 0)
			return (i);
	}
	return (0);
}

char			*get_env(char **env, char *key, t_termios term_orig)
{
	int			i;
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
		error("ERROR_KEY", term_orig);
	return (ret);
}
