/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 21:09:30 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/13 21:49:51 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		check_cmd(t_cmd *cmd, char **cmd_line)
{
	while (cmd)
	{
		if (ft_strequ(cmd->tok, *cmd_line))
		{
			cmd->callback(cmd_line + 1);
			return ;
		}
		cmd = cmd->next;
	}
	ft_printf("{red}%s{eoc}\n", MSG_CMD);
}

static void		parse_line(char *line)
{
	char		**split;

	split = ft_strsplit(line, ' ');
	if (*split)
	{
		check_cmd(env->inter.cmd, cplit);
		free(split);
		free(line);
	}
}

static void		ask_user(void)
{
	t_scene		*scene;
	char		*line;

	scene = env->e_scene;
	while (1)
	{
		get_stdin_next_line(&line);
		parse_line(line);
	}
	return ;
}

int				create_inter_thread(void)
{
	inter_init_cmd(&env->inter);
	if (pthread_create(&env->inter_thread, NULL, ask_user, NULL))
	{
		ft_printf("{red}%s\n{eoc}", MSG_THREAD);
		return (1);
	}
	return (0);
}
