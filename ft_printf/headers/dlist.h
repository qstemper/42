/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 11:17:22 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/07 11:17:24 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DLIST_H
# define DLIST_H

# include "header.h"

typedef struct		s_dlist
{
	void			*content;
	size_t			content_size;
	struct s_dlist	*p;
	struct s_dlist	*n;
}					t_dlist;

t_dlist				*dlist_new(const void *content, size_t content_size);
void				dlist_delone(t_dlist **alst, void (*del)(void *, size_t));
void				dlist_del(t_dlist **alst, void (*del)(void *, size_t));
void				dlist_add_p(t_dlist **alst, t_dlist *elem);
void				dlist_add_n(t_dlist **alst, t_dlist *elem);
void				dlist_add_ip(t_dlist **alst, t_dlist *elem, t_uint i);
void				dlist_add_in(t_dlist **alst, t_dlist *elem, t_uint i);
t_dlist				*dlist_map(t_dlist *list, t_dlist *(*f)(t_dlist *));

#endif
