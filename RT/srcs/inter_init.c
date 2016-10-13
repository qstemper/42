/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 20:50:45 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/13 21:09:20 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void			inter_add_cmd(t_cmd, **cmd, char *tok, \
		void (*callback)(char **))
{
	t_cmd			*new_cmd;

	if (!(new_cmd = (t_cmd *)malloc(sizeof(t_cmd))))
	{
		ft_printf("{red}%s{eoc}\n", MSG_MEM);
		return ;
	}
	new_cmd->tok = ft_strdup(tok);
	new_cmd->callback = callback;
	new_cmd->next = *cmd;
	*cmd = new_cmd;
}

void			inter_init_cmd(t_inter *inter)
{
	inter->cmd = NULL;
	inter->add->cmd(&inter->cmd, LIST, cmd_list);
	inter->add->cmd(&inter->cmd, REM, cmd_remove);
	inter->add->cmd(&inter->cmd, ADD, cmd_add);
	inter->add->cmd(&inter->cmd, EXPORT,  cmd_export);
	inter->add->cmd(&inter->cmd, IF_NAME, cmd_if_name);
	inter->add->cmd(&inter->cmd, RES, cmd_res);
	inter->add->cmd(&inter->cmd, EDIT, cmd_editing);
	inter->add->cmd(&inter->cmd, REC, cmd_recurs);
	inter->add->cmd(&inter->cmd, BLOCK, cmd_unblock);
}
