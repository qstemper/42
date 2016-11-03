#include "minishell.h"

static int		env_opt_i(char **tab)
{
	char		**env;
	int			i;
	int			j;

	i = 1;
	while (tab[++i])
	{
		if (!ft_strchr(tab[i], '='))
			return (-1);
	}
	if (!(env = (char **)ft_memalloc(sizeof(char *) * (i - 2))))
		return (-2);
	i = 1;
	while (env[++j])
	{
		if (!ft_strdup(env[j], tab[+i]))
			return (-2);
		ft_printf("%s\n", env[i]);
	}
}

void			builtin_env(int ac, char **tab, char **env)
{
	int			i;
	char		e;
	int			opt;

	i = -1;
	if (ac == 1)
	{
		if (env == NULL)
			ft_printf("\n");
		while (env[++i])
			ft_printf("%s\n", env[i]);
	}
	e = 0;
	opt = get_opt(CHARSET_ENV, ac, tab, e);
	if (IS(ERROR_BUILTIN_OPT, opt))
		error_builtin("ERROR_ATTR");
	if (IS(opt, ENV_I) == ENV_I)
	{
		if (env_opt_i(ac, tab) == -1)
			error_usage(3);
		else
			error("ERROR_MALLOC", term_orig);
	}
}
