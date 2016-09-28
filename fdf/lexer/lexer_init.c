/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <qstemper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 23:33:35 by qstemper          #+#    #+#             */
/*   Updated: 2016/09/28 07:09:08 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void		lexer_init_blank(t_token *toktab)
{
	int		i;

	i = 0;
	while (i < 6)
	{
		toktab[i].typetoken = Blank;
		toktab[i].size = 1;
		i++;
	}
	toktab[0].str = "\n";
	toktab[1].str = "\t";
	toktab[2].str = " ";
	toktab[3].str = "\f";
	toktab[4].str = "\r";
	toktab[5].str = "\v";
}

void		lexer_init_ponct(t_token *toktab)
{
	int		i;

	i = 6;
	while (i < TOK_NB)
	{
		toktab[i].typetoken = Ponctuation;
		toktab[i].size = 1;
		i++;
	}
	toktab[6].str = "!";
	toktab[7].str = ",";
	toktab[8].str = ".";
	toktab[9].str = ":";
	toktab[10].str = ";";
	toktab[11].str = "?";
	toktab[12].str = "_";
	toktab[13].str = ".";
}
