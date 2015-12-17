/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_check_token.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <qstemper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 23:36:22 by qstemper          #+#    #+#             */
/*   Updated: 2015/12/17 19:31:05 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int			lexer_tab(char *str, t_token *toktab, t_token *token)
{
	int		i;

	i = 0;
	while (i < TOK_NB)
	{
		if (ft_strncmp(str, toktab[i].str, toktab[i].size) == 0)
		{
			*token = toktab[i];
			token->str = str;
			return (1);
		}
		i++;
	}
	return (0);
}

int			ft_isnumber(char c)
{
	char	*str;

	str = NUMBER_CHARSET;
	if (ft_strchr(str, c) == NULL)
		return (0);
	return (1);
}

int			lexer_isnumber(char *str, t_token *token)
{
	int		i;

	if (ft_isnumber(str[0]) != 1)
		return (0);
	i = 0;
	while (str[i] != '\0' && ft_isnumber(str[i]) == 1)
		i++;
	token->typetoken = Number;
	token->str = str;
	token->size = i;
	return (1);
}

int			lexer_isalpha(char *str, t_token *token)
{
	int		i;

	if (ft_isalpha(str[0]) == 0)
		return (0);
	i = 0;
	while (str[i] != '\0' && ft_isalpha(str[i]))
		i++;
	token->typetoken = Alpha;
	token->str = str;
	token->size = i;
	return (1);
}
