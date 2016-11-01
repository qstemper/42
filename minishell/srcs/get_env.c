/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 10:54:43 by qstemper          #+#    #+#             */
/*   Updated: 2016/11/01 11:58:11 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char			*get_env(char **env, char *key)
{
	int			i;
	size_t		size;
	char		*ret;

	ret = NULL;
	i = 0;
	size = ft_strlen(key);
	while (env[i])
	{
		if (ft_strncmp(env[i], key, len) == 0)
		{
			ret = ft_strchr(env[i], '=');
			return (ret + 1);
		}
		i++;
	}
	if (ret == NULL)
		error("ERROR_KEY");
	return (ret);
}
