/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   av.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 13:25:19 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/05 15:13:47 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/ft_ls.h"

t_ls_entry			ls_newentry(char *name, char *absname)
{
	t_ls_entry		e;

	ft_bzero((void *)&e, sizeof(t_ls_entry));
	e.handle = 1;
	ft_strncpy(e.name, name, NAMESIZE);
	errno = 0;
	lstat(absname, &e.stat);
	if (errno)
	{
		e.msg = strerror(errno);
		errno = 0;
		e.type = T_ERROR;
		return (e);
	}
	if ((e.stat.st_mode & S_IFDIR) == S_IFDIR)
		e.type =  T_DIR;
	else
		e.type = T_FILE;
	return (e);
}

static t_node		*av_woa_tree(void)
{
	t_ls_entry		e;

	e = ls_newentry(".", ".");
	return (tree_new_node((void *)&e, sizeof(t_ls_entry)));
}

void				maj_env(t_ls_entry e)
{
	size_t			size;

	if (!e.handle && !IS(O_HIDE, env()->o))
		return ;
	if ((size = ft_intlen(e.stat.st_nlink)) > env()->nlinkpad)
		env()->nlinkpad = size;
	if ((size = ft_intlen(e.stat.st_size)) > env()->sizepad)
		env()->sizepad = size;
	if ((size = ft_strlen(getpwuid(e.stat.st_uid)->pw_name)) > env()->ownerlen)
		env()->ownerlen = size;
	if ((size = ft_strlen(getgrgid(e.stat.st_gid)->gr_name)) > env()->grplen)
		env()->grplen = size;
}

static t_node		*av_wa_tree(int ac, int i, char **av)
{
	int				(*s)(void *, void *);
	t_node			*root;
	t_node			*no;
	t_ls_entry		e;

	root = NULL;
	s = g_ls_select_avsort(env()->o);
	while (i < ac)
	{
		e = ls_newentry(av[i], av[i]);
		errno = 0;
		if (!(no = tree_new_node((void *)&e, sizeof(t_ls_entry))))
		{
			error(env()->av, av[i]);
			errno = 0;
			tree_del(&root, NULL);
			return (NULL);
		}
		maj_env(e);
		tree_add(&root, no, s);
		i++;
	}
	return (root);
}

t_node				*av_tree(int ac, char **av)
{
	int				i;

	i = 0;
	while (++i < ac)
	{
		if (*av[i] != '-' || ft_strlen(av[i]) == 1)
			break ;
	}
	if (i + 1 <ac)
		env()->i++;
	if (i == ac)
		return (av_woa_tree());
	return (av_wa_tree(ac, i, av));
}
