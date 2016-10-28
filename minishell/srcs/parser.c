#include "minishell.h"

static char		**pars_path(char **env)
{
	char		**tab;
	char		*str;
	DIR		*dir;
	struct dirent	*entry;
	int		i;

	str = get_env(env, "PATH");
	if (!(tab = ft_strsplit(str, ':')))
	{
		ft_fprintf(2, "{red}%s{eoc}", ERROR_PARS);
		exit(-1);
	}
	i = -1;
	while (tab[++i])
	{
		dir = opendir(tab[i]);
		if (!dir)
			continue ;
		entry = readdir(dir);
		
		closedir(dir);
	}
}

static void		exist_cmd(char *str)
{
	
}

char			*pars(char *str, char **env)
{
	char		**tab;

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
