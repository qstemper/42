/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <qstemper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 23:33:35 by qstemper          #+#    #+#             */
/*   Updated: 2015/12/01 09:55:04 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void		lexer_init(t_token *toktab)
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
	toktab[6].typetoken = Ponctuation;
	toktab[6].str = "!";
	toktab[6].size = 1;
	toktab[7].typetoken = Ponctuation;
	toktab[7].str = ",";
	toktab[7].size = 1;
	toktab[8].typetoken = Ponctuation;
	toktab[8].str = ".";
	toktab[8].size = 1;
	toktab[9].typetoken = Ponctuation;
	toktab[9].str = ":";
	toktab[9].size = 1;
	toktab[10].typetoken = Ponctuation;
	toktab[10].str = ";";
	toktab[10].size = 1;
	toktab[11].typetoken = Ponctuation;
	toktab[11].str = "?";
	toktab[11].size = 1;
	toktab[12].typetoken = Ponctuation;
	toktab[12].str = "_";
	toktab[12].size = 1;
	toktab[13].typetoken = Ponctuation;
	toktab[13].str = ".";
	toktab[13].size = 1;
	toktab[14].typetoken = Ponctuation;
	toktab[14].str = "-";
	toktab[14].size = 1;
}
