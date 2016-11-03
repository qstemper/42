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
