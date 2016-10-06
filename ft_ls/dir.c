/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 14:11:41 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/06 08:07:16 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int					entry_tree(t_node **ar, struct dirent *entry, \
		quad_t *blocks, int *i)
{
	char			absname[PATHSIZE];
	t_ls_entry		e;
	t_node			*no;

	ft_strcpy(absname, env()->path);
	ft_strcat(absname, "/");
	ft_strcat(absname, entry->d_name);
	e = ls_newentry(entry->d_name, absname);
	if (entry->d_name[0] == '.' && !((env()->o & O_HIDE) == O_HIDE))
		e.handle = 0;
	if (e.handle)
	{
		*i += 1;
		*blocks += e.stat.st_blocks;
	}
	if (!ft_strcmp(entry->d_name, ".") || !ft_strcmp(entry->d_name, ".."))
		e.handle = 0;
	if (!(no = tree_new_node((void *)&e, sizeof(t_ls_entry))))
		return (error(env()->av, absname));
	tree_add(ar, no, g_ls_select_sort(env()->o));
	maj_env(e);
	return (1);
}
