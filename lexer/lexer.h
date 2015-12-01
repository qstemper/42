/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <qstemper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 10:22:25 by qstemper          #+#    #+#             */
/*   Updated: 2015/12/01 09:55:48 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H

# define LEXER_H

# include "libft.h"

# define TOK_NB 15
# define NUMBER_CHARSET "0123456789xXaAbBcCdDeEfF"
# define PONCT_CHARSET "!,.:;?_-"

typedef enum	e_toktyp
{
	Number,
	Alpha,
	Blank,
	Ponctuation,
	Error
}				t_toktyp;

typedef struct	s_token
{
	t_toktyp	typetoken;
	char		*str;
	int			size;
}				t_token;

void			lexer_init(t_token *toktab);
char			*assign_token(t_toktyp typetoken);
int				lexer_isblank(char *str, t_token *toktab, t_token *token);
int				ft_isnumber(char c);
int				lexer_isnumber(char *s, t_token *token);
int				lexer_isalpha(char *str, t_token *token);
int				ft_isponct(char c);
int				lexer_isponct(char *str, t_token *token);
int				lexer(char *str, t_list **list);

#endif
