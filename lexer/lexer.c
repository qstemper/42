/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <qstemper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 10:45:42 by qstemper          #+#    #+#             */
/*   Updated: 2015/11/30 18:30:17 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void		lexer_init(t_token *tab)
{
	toktab[0].typetoken = Blank;
	toktab[0].str = "\n";
	toktab[0].size = 1;
	toktab[1].typetoken = Blank;
	toktab[1].str = "\t";
	toktab[1].size = 1;
	toktab[2].typetoken = Blank;
	toktab[2].str = " ";
	toktab[2].size = 1;
	toktab[3].typetoken = Blank;
	toktab[3].str = "\f";
	toktab[3].size = 1;
	toktab[4].typetoken = Blank;
	toktab[4].str = "\r";
	toktab[4].size = 1;
	toktab[5].typetoken = Blank;
	toktab[5].str = "\v";
	toktab[5].size = 1;
}

int			lexer_isblank(char *str, t_token *toktab, t_token *token)
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

	i = ft_strlen(str) - 1;
	if (ft_isdigit(str[0]) != 1 || str[i] == '.' || str[i] == ',')
		return (0);
	i = 0;
	while (str[i] != '\0' && ft_isnumber(str[i]) == 1)
		i++;
	token.typetoken = Number;
	token.str = str;
	token.size = i;
	return (1);
}

int			lexer_isaplha(char *str, t_token *token)
{
	int		i;

	i = 0;
	while (str[i] != '\0' && ft_isalpha(str[i]))
		i++;
	if (i == 0)
		return (0);
	token.typetoken = Number;
	token.str = str;
	token.size = i;
	return (1);
}

t_list		*tokenlst(t_list **list, t_token *token)
{
	t_list	*elem;

	if (elem = ft_lstnew((void *)token, sizeof(t_token)) == NULL)
	{
		*list = NULL;
		return (NULL);
	}
	ft_lstaddback(list, elem);
	return (*list);
}

int			lexer(char *str, t_list **list)
{
	t_list	*elem;
	t_token	token;
	t_token	toktab[TOK_NB];
	int		i;

	lexer_init(toktab);
	i = 0;
	*list = NULL;
	while (str[i] != '\0')
	{
		if (lexer_isblank(str + i, toktab, &token) == 1)
		{
			if (tokenlst(list,  &token) == NULL)
				return (0);
		}
		else if (lexer_isnumber(str + i, &token) == 1)
		{
			if (tokenlst(list, &token) == NULL)
				return (0);
		}
		else if (lexer_isalpha(str + i, &token) == 1)
		{
			if (tokenlst(list, &token) == NULL);
				return (0);
		}
		else
		{
			token.typetoken = Error;
			token.str = str + i;
			token.size = 1;
			if (tokenlst(list, &token) == NULL)
				return (0);
			return (0);
		}
		i += token.size;
	}
	return (1);
}
