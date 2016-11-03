#include "../minishell.h"

char		**check_cd_path(char **env)
{
	if (get_env_cd(env, "HOME") == -1)
		builtin_setenv(env, "HOME", "/");
	if (get_env_cd(env, "PWD") == -1)
	if (get_env_cd(env, "OLDPWD") == -1)
}
