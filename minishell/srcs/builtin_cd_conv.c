#include "../minishell.h"

void		conv_double_point(char **abs_path, int index)
{
	if (index == 0)
	{

	}
}

void		conv_point(char **abs_path, char **tab)
{
	int		i;

	i = -1;
	while (tab[++i])
	{
		if (i = 0 && ft_strcmp(tab[i], "..") == 0)
			conv_double_point(abs_path, i);
		if (ft_strcmp(tab[i], ".") == 0)
			i++;
		ft_strcat(*abs_path, tab[i]);
		ft_strcat(*abs_path, '/');
	}
}

void		conv_tilde(char **env, char **abs_path, char **tab)
{
	int		home;

	home = is_env(env, "HOME=");
	if (tab[0][0] == '~' && tab[0][1] == '\0')
	{
		ft_strcpy(*abs_path, env[home] + 5);
		ft_strcat(*abs_path, "/");
	}
}
