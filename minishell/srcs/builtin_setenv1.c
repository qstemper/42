#include "minishell.h"

static char		**real_setenv(char **env, char *str, char *value)
{
	int			i;
	int			ret;

	i = -1;
	ret = 0;
	while(env[++i])
	{
		if ((ret = ft_strcmp(env[i], str) == 0)
			break ;
	}
	if (ret != 0)
	{
		if ((env = if_ret_not_null(ret, env, str, value)) == NULL)
			return (NULL);
	}
	else
	{
		if ((env = if_ret_null(env, str, value, i)) == NULL)
			return (NULL);
	}
	return (env);
}

char			**builtin_setenv(int ac, char **tab, char **env, t_termios term_orig)
{
	int			i;

	i = -1;
	if (ac != 3)
	{
		ft_fprintf(2, "{red}Too Few Or Too Much Arguments{eoc}\n");
		error_usage(1);
		return (NULL);
	}
	while (++i < ac)
	{
		if (av[i][0] == '-')
		{
			error_usage(1);
			return (NULL);
		}
	}
	if ((env = real_setenv(env, tab[1], tab[2])) == NULL) 
		error("ERROR_MALLOC", term_orig);
	return (env);
}
