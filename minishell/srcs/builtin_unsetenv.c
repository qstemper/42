#include "../minishell.h"

static void		real_unsetenv(char **env, char *str)
{
	int			i;
	int			j;
	int			ret;

	i = -1;
	while (env[++i])
	{
		if ((ret = ft_strcmp(env[i], str)) == 0)
		{
			j = i;
			free(env[i]);
			break ;
		}
	}
	if (ret == 0)
	{
		while (env[++i])
			;
		env[j] = env[--i];
		env[i] = NULL;
	}
}

void			builtin_unsetenv(int ac, char **tab, char **env)
{
	if (ac != 2)
	{
		ft_fprintf(2, "{red}Too Few Or Too Much Arguments{eoc}\n");
		error_usage(2);
		return (NULL);
	}
	if (av[1][0] == '-')
	{
		error_usage(1);
		return (NULL);
	}
	real_unsetenv(env, tab[1]);
}
