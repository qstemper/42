/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <qstemper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 10:22:25 by qstemper          #+#    #+#             */
/*   Updated: 2015/11/30 18:30:18 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H

# define LEXER_H

# include "libft.h"

# define TOK_NB 6
# define NUMBER_CHARSET "0123456789xXaAbBcCdDeEfF,."

typedef enum	e_toktyp
{
	Number,
	Alpha,
	Blank,
	Error
}				t_toktyp;



typedef struct	s_token
{
	t_toktyp	typetoken;
	char		*str;
	int			size;
}				t_token;

t_list			*lexer(char *str);

#endif
