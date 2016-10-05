/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 09:15:43 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/05 14:28:41 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/ft_ls.h"

char				*fmt_yhm(t_ls_entry *e, char *buff)
{
	char			*cp;
	static time_t	now;
	time_t			d;

	if (now == 0)
		now = time(NULL);
	ft_bzero((void *)buff, 6);
	d = e->stat.st_mtimespec.tv_sec;
	if (((d + SIXMONTH) > now) && (d < (now + SIXMONTH)))
	{
		cp = ctime(&e->stat.st_mtimespec.tv_sec) + 11;
		ft_strncpy(buff, cp, 5);
	}
	else
	{
		cp = ctime(&e->stat.st_mtimespec.tv_sec) + 20;
		buff[0] = ' ';
		ft_strncpy(buff + 1, cp, 4);
	}
	return (buff);
}

char				*fmt_month(t_ls_entry *e, char *buff)
{
	char			*cp;

	ft_bzero((void *)buff, 6);
	cp = ctime(&e->stat.st_mtimespec.tv_sec) + 4;
	return (cp);
}

char				*fmt_day(t_ls_entry *e, char *buff)
{
	char			*cp;

	ft_bzero((void *)buff, 6);
	cp = ctime(&e->stat.st_mtimespec.tv_sec) + 8;
	return (cp);
}
