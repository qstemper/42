/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 12:54:16 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/13 11:40:48 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			p_standard(void *p, size_t size)
{
	t_ls_entry	*e;

	e = (t_ls_entry *)p;
	if (!e->handle && !((env()->o & O_HIDE) == O_HIDE))
		return ;
	env()->i++;
	ft_printf("%s\n", e->name);
	(void)size;
}

void			p_cstandard(void *p, size_t size)
{
	t_ls_entry	*e;

	e = (t_ls_entry *)p;
	if (e->type == T_FILE)
		ft_printf("%s\n", e->name);
	else if (e->type == T_DIR)
		ft_printf("{cyan}%s{eoc}\n", e->name);
	else
		ft_printf("{red}%s{eoc}\n", e->name);
	(void)size;
}

void			p_long(void *p, size_t size)
{
	t_ls_entry	*e;
	char		buff[6][6];
	char		bufflink[LINKSIZE + 1];

	e = (t_ls_entry *)p;
	if (!e->handle && !((env()->o & O_HIDE) == O_HIDE))
		return ;
	env()->i++;

	ft_printf("%c%s%s%s%c %*d % -*s % -*s% *d %.3s %.2s %s %s", \
			fmt_file_mode(e), \
			fmt_owner_perm(e, buff[0]), \
			fmt_group_perm(e, buff[1]), \
			fmt_other_perm(e, buff[2]), \
			fmt_attribute(e), \
			env()->nlinkpad, fmt_nblink(e), \
			env()->ownerlen + 1, fmt_owner(e), \
			env()->grplen + 1, fmt_group(e), \
			env()->sizepad + 1, fmt_size(e), \
			fmt_month(e, buff[3]), \
			fmt_day(e, buff[4]), \
			fmt_yhm(e, buff[5]), e->name);
	if ((e->stat.st_mode & S_IFLNK) == S_IFLNK)
		ft_printf(" -> %s", fmt_link(e, bufflink));
	ft_putendl("");
	(void)size;
}

void			p_clong(void *p, size_t size)
{
	(void)p;
	(void)size;
}
