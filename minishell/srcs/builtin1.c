#include "../minishell.h"

void		builtin_echo(int ac, char **tab)
{
	int		opt;
	char	e;

	e = 0;
	opt = get_opt(CHARSET_ECHO, ac, tab, &e);
	if (IS(ERROR_BUILTIN_OPT, opt))
		error_builtin("ERROR_ATTR");
	i = 0;
	while (++i < ac)
	{
		if (ft_strcmp(tab[i], "-n") == 0)
			continue ;
		ft_printf("%s", tab[i]);
		if (tab[i + 1] != '\0')
			ft_printf(" ");
	}
	if (IS(opt, ECHO_N) == ECHO_N)
		return ;
	ft_printf("\n");
}

void		builtin_exit(t_termios term_orig)
{
	if (tcsetattr(0, TCSANOW, &term_orig) == -1)
		error("ERROR_TERM",  term_orig);
	exit(0);
}

void		builtin_cd(int ac, char **tab, char **env)
{
	int		opt;
	int		skip;
	char	e;
	char	*cpy_pwd

							GERER -L -P -  . .. ~ cd de base
	if (check_cd_path(ac, tab, env) == -1)
		return ;
	opt = get_opt(CHARSET_CD, ac, tab, &e);
	if (IS(ERROR_BUILTIN_OPT, opt))
		error_builtin("ERROR_ATTR");
	skip = skip_opt(ac, tab);
	cpy_pwd = get_env(env, "OLDPWD");
	if ()
	if (IS(opt, CD_L) == CD_L)
	{
		
	}
}
