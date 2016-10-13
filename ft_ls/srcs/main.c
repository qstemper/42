/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 12:12:47 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/13 13:32:42 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_env				*env(void)
{
	static t_env	e;

	return (&e);
}

void				ls_av(void *p, size_t size)
{
	t_ls_entry		*e;
	void			(*print)(void *, size_t);

	ft_bzero((void *)env()->path, PATHSIZE);
	e = (t_ls_entry *)p;
	(void)size;
	print = g_ls_select_print(env()->o);
	if (e->type == T_ERROR)
		ft_fprintf(2, "%s: %s: %s\n", env()->av, e->name, e->msg);
	else if (e->type == T_FILE)
	{
		env()->i++;
		print((void *)e, sizeof(t_ls_entry));
	}
	else
		ls_dir((void *)e, sizeof(t_ls_entry));
}

static int			ft_put_usage(char e)
{
	ft_fprintf(2, FMT1, env()->av, "Illegal Option", e);
	ft_fprintf(2, FMT2, "usage", env()->av, CHARSET_O, "file ...");
	return (0);
}

static void			init_env(void)
{
	env()->i = 0;
	env()->nlinkpad = 0;
	env()->sizepad = 0;
	env()->ownerlen = 0;
	env()->grplen = 0;
}

int					main(int ac, char **av)
{
	t_node			*root;
	char			e;

	init_env();
	env()->av = ft_name(av[0]);
	e = 0;
	env()->o = get_opt(CHARSET_O, ac, av, &e);
	if (IS(O_PRIVATE_ERROR, env()->o))
		return (ft_put_usage(e));
	if ((root = av_tree(ac, av)))
	{
		tree_do_inf(root, ls_av);
		tree_del(&root, NULL);
	}
	return (0);
}
