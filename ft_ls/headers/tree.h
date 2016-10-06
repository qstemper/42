/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 11:12:05 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/06 09:15:23 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_H
# define TREE_H

typedef struct		s_node
{
	void			*content;
	size_t			content_size;
	struct s_node	*sonleft;
	struct s_node	*sonright;
	struct s_node	*f;
}					t_node;

void				tree_do_inf(t_node *r, void (*d)(void *, size_t));
t_node				*tree_new_node(void *content, size_t size);
void				tree_add(t_node **ar, t_node *no, int(*s)(void *, void *));
void				tree_del(t_node **ar, void (*d)(void *, size_t));

#endif
