/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 13:51:37 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/06 08:09:10 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		*ft_memdup(void *p, size_t size)
{
	t_uchar		*cp;
	size_t		i;

	if (!(cp = (t_uchar *)ft_memalloc(size)))
		return (NULL);
	i = 0;
	while (i < size)
	{
		cp[i] = ((t_uchar *)p)[i];
		i++;
	}
	return ((void*)cp);
}

void			tree_doinf(t_node *r, void (*d)(void *, size_t))
{
	if (r && r->sonleft)
		tree_doinf(r->sonleft, d);
	if (r)
		d(r->content, r->content_size);
	if (r && r->sonright)
		tree_doinf(r->sonright, d);
}

t_node			*tree_newnode(void *content, size_t size)
{
	t_node		*no;

	if (!content)
		return (NULL);
	no = (t_node *)ft_memalloc(sizeof(t_node));
	if (!no)
		return (NULL);
	no->content = ft_memdup(content, size);
	if (!no->content)
	{
		ft_memdel((void **)&no);
		return (NULL);
	}
	no->content_size = size;
	return (no);
}

void			tree_add(t_node **ar, t_node *no, int (*s)(void *, void *))
{
	if (!*ar)
	{
		*ar = no;
		return ;
	}
	if (s((*ar)->content, no->content))
	{
		if ((*ar)->sonright)
		{
			tree_add(&(*ar)->sonright, no, s);
			return ;
		}
		(*ar)->sonright = no;
		no->f = (*ar);
	}
}

void			tree_del(t_node **ar, void (*d)(void *, size_t))
{
	if (*ar && (*ar)->sonleft)
		tree_del(&(*ar)->sonleft, d);
	if (*ar && (*ar)->sonright)
		tree_del(&(*ar)->sonright, d);
	if (d)
		d((*ar)->content, (*ar)->content_size);
	ft_memdel((void **)&(*ar)->content);
	ft_memdel((void **)ar);
}
