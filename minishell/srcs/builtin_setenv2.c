#include "minishell.h"

static void		destroy_env(char **env)
{
	int			i;

	i = -1;
	while (env[++i])
		free(env[i]);
	free(env);
}

static char		**malloc_env(char **env, int i)
{
	char		**new_env;
	int			nei;
	int			j;

	new_env = NULL;
	if (i == 0)
		return (new_env);
	if (!(new_env = (char **)ft_memalloc(sizeof(char *) * (i + 2))))
		return (new_env);
	new_env[i + 1] = NULL;
	nei = -1;
	while (env[++nei])
	{
		j = ft_strlen(env[nei]);
		if (!(new_env[nei] = ft_strdup(env[nei])))
				return (NULL);
	}
	return (new_env);
}

static void		new_env(char **env, char *str, char *value)
{
	if (!(env[++i] = ft_strnew(ft_strlen(str) + ft_strlen(value) + 1)))
		return (NULL);
	ft_strcpy(env[i], str);
	ft_strcat(env[i], "=");
	ft_strcat(env[i], value);
}

char			**if_ret_not_null(char **env, char *str, char *value)
{
	char		**tmp;

	tmp = NULL;
	if ((tmp = malloc_env(env, i) == NULL)
		return (NULL);
	destroy_env(env);
	env = tmp;
	env = new_env(env, str, value);
	return (env);
}

char			**if_ret_null(char **env, char *str, char *value, int i)
{
	free(env[i]);
	env = new_env(env, str, value);
	return (env);
}
