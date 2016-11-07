#include "minishell.h"

static void		check_new_var(char **tab, char **env, t_termios term_orig)
{
	char		*str[3];
	char		**tmp;
	int			skip;

	skip = skip_opt(ac, tab);
	tmp = NULL;
	while (ft_strchr(tab[skip], '=') != NULL)
	{
		str[0] = tab[0];
		if (!(tmp = ft_strsplit(tab[skip], '=')) == NULL)
			error("ERROR_MALLOC", term_orig);
		str[1] = tmp[0];
		str[2] = tamp[1];
		while (tmp++)
			free(*tmp);
		free(tmp);
		builtin_setenv(3, str, env, term_orig);
		skip+;
	}
	if (!tab[skip] == NULL)
	{
		while (env++)
			printf("%s\n", *env);
	}
}

static void		check_new_cmd(int ac, char **tab, char **env, \
	t_termios term_orig)
{
	int			i;
	int			j;
	char		**path;
	t_dirent	dir;
	pid_t		pid;

	i = skip_opt(ac, tab);
	j = -1;
	pid = fork();
	while (ft_strncmp(env[++j], "PATH", 4) != 0)
		;
	path = ft_split(env[j]);
	j = -1;
	while (42)
	{
		if ((dir = readdir(path[++j])) == NULL)
			return ;
		if (ft_strcmp(tab[i], dir.d_name) == 0 && pid == 0)
			execve(dir.d_name, tab, env);
		wait(pid);
	}
}

static char		**copy_env(char **env, t_termios term_orig)
{
	int			i;
	char		**env_cpy;

	i = -1;
	env_cpy = NULL;
	while (env[++i])
	{
		if ((env_cpy[i] = ft_strnew(ft_strlen(env[i]) + 1)) == NULL)
			error("ERROR_MALLOC", term_orig);
		ft_strcpy(env_cpy[i], env[i]);
	}
	return (env_cpy);
}

static int		new_env(char **tab, char ***env)
{
	int			i;
	int			j;

	i = 1;
	if (ft_strlen(tab[i]) != 2)
		return (-1);
	while (tab[++i])
	{
		if (!ft_strchr(tab[i], '='))
			break ;
	}
	if (!(*env = (char **)ft_memalloc(sizeof(char *) * (i - 2))))
		return (-2);
	j = -1;
	i = 1;
	while ((*env)[++j])
	{
		if (!ft_strdup((*env)[j], tab[++i]))
			return (-2);
	}
	return (0);
}

void			builtin_env(int ac, char **tab, char **env, t_termios term_orig)
{
	char		**env_cpy;
	char		e;
	int			opt;
	int			ret;

	e = 0;
	opt = get_opt(CHARSET_ENV, ac, tab, &e);
	env_cpy = NULL;
	if (IS(ERROR_BUILTIN_OPT, opt))
		error_builtin("ERROR_ATTR");
	else if (IS(opt, ENV_I) == ENV_I)
	{
		if ((ret = new_env(tab, &env_cpy)) == -1)
			error_usage(3);
		else if (ret == -2)
			error("ERROR_MALLOC", term_orig);
	}
	else
		env_cpy = copy_env(env, term_orig);
	check_new_var(tab, env_cpy, term_orig);
	check_new_cmd(ac, tab, env_cpy, term_orig);
}
