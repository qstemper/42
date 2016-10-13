/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <qstemper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/17 14:16:01 by qstemper          #+#    #+#             */
/*   Updated: 2015/11/26 14:43:54 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_parts(char const *s, char c)
{
	int		cmpt;
	int		var;
	int		i;

	cmpt = 0;
	var = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (var == 0 && s[i] != c)
		{
			var = 1;
			cmpt++;
		}
		if (var == 1 && s[i] == c)
			var = 0;
		i++;
	}
	return (cmpt);
}

static size_t	ft_wordslength(char const *s, char c)
{
	size_t	length;
	int		i;

	length = 0;
	i = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		length++;
		i++;
	}
	return (length);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	size_t	wd_len;
	int		wd_nb;
	int		i;
	int		j;

	i = 0;
	j = 0;
	wd_nb = ft_count_parts(s, c);
	if ((tab = (char **)malloc(sizeof(char *) * wd_nb + 1)) == NULL)
		return (NULL);
	tab[wd_nb] = NULL;
	while (wd_nb-- > 0)
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		wd_len = ft_wordslength(s + i, c);
		if (wd_len > 0)
		{
			if (!(tab[j++] = ft_strsub(s, i, wd_len)))
				return (NULL);
		}
		i = i + wd_len;
	}
	return (tab);
}
