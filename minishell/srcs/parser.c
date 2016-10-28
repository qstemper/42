#include "minishell.h"

static char	**pars_path(char **env)
{
	char	**tab;
	char	*str;

	str = get_env(env, "PATH");
	if (!(tab = ft_strsplit(str, ':')))
	{
		ft_fprintf(2, "{red}%s{eoc}", ERROR_PARS);
		exit(-1);
	}
	
}

static void	exist_cmd(char *str)
{
	
}

char		*pars(char *str, char **env)
{
	char	**tab;
	char	

	tab = NULL;
	if (!(tab = ft_strsplit(str, ' ')))
	{
		ft_fprintf(2, "{red}%s{eoc}", ERROR_PARS);
		exit(-1);
	}
	pars_path(env);
	exist_cmd(tab[0]);
	return (str);
}
