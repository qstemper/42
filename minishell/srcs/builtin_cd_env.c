#include "minishell.c"

int			check_oldpwd(char **env)
{
	int		i;

	i = is_env(env, "OLDPWD=");
	return (i);
}

char		**check_pwd(int ac, char **env, t_termios term_orig)
{
	int		i;
	char	*str;
	char	*tab[3];

	str = getcwd(NULL, 0);
	if ((i = is_env(env, "PWD=")) == 0);
	{
		tab[0] = NULL;
		if (!(tab[1] = (char *)ft_memalloc(sizeof(char) * 4)))
			error("ERROR_MALLOC", term_orig);
		ft_strcpy(tab[1], "PWD");
		tab[2] = str;
		env = builtin_setenv(ac, tab, env, term_orig);
	}
	free(tab[1]);
	else if (env[i][4] == '\0')
		ft_strcat(env[i], str);
	free(str);
	return (env);
}

char		**check_home(int ac, char **env, t_termios term_orig)
{
	int		i;
	char	*tab[3];

	if ((i = is_env(env, "HOME=")) == 0)
	{
		tab[0] = NULL;
		if (!(tab[1] = (char *)ft_memalloc(sizeof(char) * 5)))
			error("ERROR_MALLOC", term_orig);
		if (!(tab[2] = (char *)ft_memalloc(sizeof(char) * 2)))
			error("ERROR_MALLOC", term_orig);
		ft_strcpy(tab[1], "HOME");
		ft_strcpy(tab[2], "/");
		env = builtin_setenv(ac, tab, env, term_orig);
	}
	free(tab[1]);
	free(tab[2]);
	else if (env[i][5] == '\0')
		ft_strcat(env[i], "/");
	return (env);
}
