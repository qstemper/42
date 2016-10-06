/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_avsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 12:43:11 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/06 08:08:15 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				avs_lex(void *s1, void *s2)
{
	t_ls_entry	*e1;
	t_ls_entry	*e2;

	e1 = (t_ls_entry *)s1;
	e2 = (t_ls_entry *)s2;
	if (e2->type > e1->type)
		return (1);
	else if (e2->type < e1->type)
		return (0);
	return ((ft_strcmp(e1->name, e2->name) < 0));
}

int				avs_rlex(void *s1, void *s2)
{
	t_ls_entry	*e1;
	t_ls_entry	*e2;

	e1 = (t_ls_entry *)s1;
	e2 = (t_ls_entry *)s2;
	if (e2->type > e1->type)
		return (1);
	else if (e2->type < e1->type)
		return (0);
	if (e1->type == T_ERROR)
		return ((ft_strcmp(e1->name, e2->name) < 0));
	return ((ft_strcmp(e1->name, e2->name) > 0));
}

int				avs_modt(void *s1, void *s2)
{
	t_ls_entry	*e1;
	t_ls_entry	*e2;

	e1 = (t_ls_entry *)s1;
	e2 = (t_ls_entry *)s2;
	if (e2->type > e1->type)
		return (1);
	else if (e2->type < e1->type)
		return (0);
	if (e1->type == T_ERROR)
		return ((ft_strcmp(e1->name, e2->name) < 0));
	if (e1->stat.st_mtimespec.tv_sec - e2->stat.st_mtimespec.tv_sec > 0)
		return (1);
	else if (e1->stat.st_mtimespec.tv_sec - e2->stat.st_mtimespec.tv_sec < 0)
		return (0);
	else
		return (s_lex(s1, s2));
}

int				avs_rmodt(void *s1, void *s2)
{
	t_ls_entry	*e1;
	t_ls_entry	*e2;

	e1 = (t_ls_entry *)s1;
	e2 = (t_ls_entry *)s2;
	if (e2->type > e1->type)
		return (1);
	else if (e2->type < e1->type)
		return (0);
	if (e1->type == T_ERROR)
		return ((ft_strcmp(e1->name, e2->name) < 0));
	if (e1->stat.st_mtimespec.tv_sec - e2->stat.st_mtimespec.tv_sec > 0)
		return (0);
	else if (e1->stat.st_mtimespec.tv_sec - e2->stat.st_mtimespec.tv_sec < 0)
		return (1);
	else
		return (s_rlex(s1, s2));
}
