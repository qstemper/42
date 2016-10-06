/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_name.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 09:05:54 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/06 10:21:18 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*fmt_owner(t_ls_entry *e)
{
	return (getpwuid(e->stat.st_uid)->pw_name);
}

char		*fmt_group(t_ls_entry *e)
{
	return (getgrgid(e->stat.st_gid)->gr_name);
}

int			fmt_nblink(t_ls_entry *e)
{
	return (e->stat.st_nlink);
}

int			fmt_size(t_ls_entry *e)
{
	return (e->stat.st_size);
}

char		*fmt_link(t_ls_entry *e, char *buff)
{
	char	absname[PATHSIZE + 1];

	ft_bzero((void *)buff, LINKSIZE + 1);
	ft_bzero((void *)absname, PATHSIZE + 1);
	ft_strcpy(absname, env()->path);
	ft_strcat(absname, "/");
	ft_strcat(absname, e->name);
	if (readlink(absname, buff, (size_t)LINKSIZE) > 0)
		error(env()->av, e->name);
	return (buff);
}
