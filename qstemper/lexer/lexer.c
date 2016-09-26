/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <qstemper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 10:45:42 by qstemper          #+#    #+#             */
/*   Updated: 2015/12/18 16:33:12 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

char		*assign_token(t_toktyp typetoken)
{
	if (typetoken == Blank)
		return ("Caractere blanc");
	if (typetoken == Alpha)
		return ("Constante alphabetique");
	if (typetoken == Number)
		return ("Constante numerique");
	if (typetoken == Ponctuation)
		return ("Ponctuation");
	if (typetoken == Error)
		return ("Erreur de caractere");
	return (0);
}

t_list		*tokenlst(t_list **list, t_token *token)
{
	t_list	*elem;

	if ((elem = ft_lstnew((void *)token, sizeof(t_token))) == NULL)
	{
		*list = NULL;
		return (NULL);
	}
	ft_lstaddback(list, elem);
	return (*list);
}

int			tok_error(char *str, t_list **list, t_token *token)
{
	token->typetoken = Error;
	token->str = str;
	token->size = 1;
	tokenlst(list, token);
	return (0);
}

int			tok_list_cons(char *str, t_list **list, t_token *toktab)
{
	int		i;
	int		ret;
	t_token	token;

	i = 0;
	while (str[i] != '\0')
	{
		if (lexer_tab(str + i, toktab, &token) == 1)
			;
		else if ((ret = lexer_isnumber(str + i, &token)) == 1)
			;
		else if ((ret = lexer_isalpha(str + i, &token)) == 1)
			;
		else if (tok_error(str + i, list, &token) == 0)
		{
			ft_lstdel(list, NULL);
			return (0);
		}
		if (tokenlst(list, &token) == NULL)
			return (0);
		i += token.size;
	}
	return (1);
}

int			lexer(char *str, t_list **list)
{
	t_token	toktab[TOK_NB];

	lexer_init_blank(toktab);
	lexer_init_ponct(toktab);
	*list = NULL;
	return (tok_list_cons(str, list, toktab));
}
