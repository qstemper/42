/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 13:44:31 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/06 11:53:30 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		(*g_ls_select_avsort(int o))(void *, void *)
{
	if ((o & (O_TIME | O_REVE)) != 0)
	{
		if ((o & (O_TIME | O_REVE)) == O_TIME)
			return (avs_modt);
		else if ((o & (O_TIME | O_REVE)) == O_REVE)
			return (avs_rlex);
		else
			return (avs_rmodt);
	}
	else
		return (avs_lex);
}

int		(*g_ls_select_sort(int o))(void *, void *)
{
	if ((o & (O_TIME | O_REVE)) != 0)
	{
		if ((o & (O_TIME | O_REVE)) == O_TIME)
			return (s_modt);
		else if ((o & (O_TIME | O_REVE)) == O_REVE)
			return (s_rlex);
		else
			return (s_rmodt);
	}
	else
		return (s_lex);
}

void	(*g_ls_select_print(int o))(void *, size_t)
{
	if ((o & (O_LONG | O_COLOR)) != 0)
	{
		if ((o & (O_LONG | O_COLOR)) == O_LONG)
			return (p_long);
		else if ((o & (O_LONG | O_COLOR)) == O_COLOR)
			return (p_cstandard);
		else
			return (p_clong);
	}
	else
		return (p_standard);
}
