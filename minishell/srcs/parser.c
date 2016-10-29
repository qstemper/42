#include "minishell.h"

static void		exist_cmd(char **tab)
{
	char		*str;

	str = tab[0];
	if (ft_strcmp(str, ECHO) == 0)
		builtin_echo(tab);
	else if (ft_strcmp(str, CD) == 0)
		builtin_cd(tab);
	else if (ft_strcmp(str, SET_E) == 0)
		builtin_setenv(tab);
	else if (ft_strcmp(str, UNSET_E) == 0)
		builtin_unsetenv(tab);
	else if (ft_strcmp(str, ENV) == 0)
		builtin_env(tab);
	else if (ft_strcmp(str, EXIT) == 0)
		builtin_exit(tab);
}

static char		**pars_path(char **tab_path, char **env)
{
	char		*str;

	str = get_env(env, "PATH");
	if (!(tab_path = ft_strsplit(str, ':')))
	{
		ft_fprintf(2, "{red}%s{eoc}", ERROR_PARS);
		exit(-1);
	}
	return (tab_path);
}

char			*pars(char *str, char **env)
{
	char		**tab;
	char		**tab_path;
	DIR		*dir;
	t_dirent	*entry;
	int		i;

	tab = NULL;
	if (!(tab = ft_strsplit(str, ' ')))
	{
		ft_fprintf(2, "{red}%s{eoc}", ERROR_PARS);
		exit(-1);
	}
	tab_path = pars_path(tab_path, env);
	exist_cmd(tab);
	i = -1;
	while (tab_path[++i])
	{
		dir = opendir(tab[i]);
		if (!dir)
			continue ;
		while ((entry = readdir(dir)))
		closedir(dir);
	}
	return (str);
}
