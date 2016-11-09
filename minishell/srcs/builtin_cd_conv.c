#include "../minishell.h"

static char		*conv_point(char **env, char *str, char *abs_path, \
		t_termios term_orig)
{

}

static char		*conv_tilde(char **env, char *str, t_termios term_orig)
{
	int			home;
	int			len;
	char		*abs_path;
	char		*tab;

	len = 2;
	abs_path == NULL;
	home = is_env(env, "HOME=");
	if (str[0] == '~' && (str[1] == '\0' || str[1] == '/'))
	{
		if (str[1] == '/' && str[2])
			len = ft_strlen(str);
		if (!(abs_path = (char *)ft_memalloc(char) * \
				(ft_strlen(env[home] + len - 4)))
			error("ERROR_MALLOC", term_orig);
		ft_strcpy(abs_path, env[home] + 5);
		ft_strcat(abs_path, "/");
		if (len > 2)
			ft_strcat(abs_path, str + 2);
	}
	return (abs_path);
}
