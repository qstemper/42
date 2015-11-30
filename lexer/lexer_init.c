/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <qstemper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 23:33:35 by qstemper          #+#    #+#             */
/*   Updated: 2015/11/30 23:35:52 by qstemper         ###   ########.fr       */
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
}
