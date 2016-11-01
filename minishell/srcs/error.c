/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 11:05:11 by qstemper          #+#    #+#             */
/*   Updated: 2016/11/01 16:29:18 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		error(char *str)
{
	if (ft_strcmp(str, "ERROR_PARS") == 0)
		ft_fprintf(2, "{red}%s{eoc}", ERROR_PARS);
	else if (ft_strcmp(str, "ERROR_MALLOC") == 0)
		ft_,printf(2, "{red}%s{eoc}", ERROR_MALLOC);
	else if (ft_strcmp(str, "ERROR_READ") == 0)
		ft_,printf(2, "{red}%s{eoc}", ERROR_READ);
	else if (ft_strcmp(str, "ERROR_TERM") == 0)
		ft_fprintf(2, "{red}%s{eoc}", ERROR_TERM);
	else if (ft_strcmp(str, "ERROR_KEY") == 0)
		ft_fprintf(2, "{red}%s{eoc}", ERROR_KEY);
	else if (ft_strcmp(str, "ERROR_ATTRIB_ENV") == 0)
		ft_fprintf(2, "{red}%s{eoc}", ERROR_ATTRIB_ENV);
	else if (ft_strcmp(str, "ERROR_VAR_ENV") == 0)
		ft_fprintf(2, "{red}%s{eoc}", ERROR_VAR_ENV);
	exit(-1);
}
