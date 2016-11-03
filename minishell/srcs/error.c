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

void		error_usage(int error)
{
	if (error == 1)
		ft_fprintf(2, "{grey}Usage : <name> <value>{eoc}\n");
	else if (error == 2)
		ft_fprintf(2, "{grey}Usage : <name>{eoc}\n");
}

void		error_builtin(char *str)
{
	if (ft_strcmp(str, "ERROR_ECHO") == 0)
		ft_fprintf(2, "{red}%s{eoc}", ERROR_ECHO);
	else if (ft_strcmp(str, "ERROR_ATTR") == 0)
		ft_fprintf(2, "{red}%s{eoc}", ERROR_ATTRIB);
	else if (ft_strcmp(str, "ERROR_OLDPWD") == 0)
		ft_fprintf(2, "{red}%s{eoc}", ERROR_OLDPWD);
	else if (ft_strcmp(str, "ERROR_ATTRIB_ENV") == 0)
		ft_fprintf(2, "{red}%s{eoc}", ERROR_ATTRIB_ENV);
	else if (ft_strcmp(str, "ERROR_VAR_ENV") == 0)
		ft_fprintf(2, "{red}%s{eoc}", ERROR_VAR_ENV);
}

void		error_pars(char *str)
{
	if (ft_strcmp(str, "ERROR_PARS") == 0)
		ft_fprintf(2, "{red}%s{eoc}", ERROR_PARS);
}

void		error(char *str, t_termios term_orig)
{
	if (ft_strcmp(str, "ERROR_MALLOC") == 0)
		ft_,printf(2, "{red}%s{eoc}", ERROR_MALLOC);
	else if (ft_strcmp(str, "ERROR_READ") == 0)
		ft_fprintf(2, "{red}%s{eoc}", ERROR_READ);
	else if (ft_strcmp(str, "ERROR_TERM") == 0)
		ft_fprintf(2, "{red}%s{eoc}", ERROR_TERM);
	else if (ft_strcmp(str, "ERROR_KEY") == 0)
		ft_fprintf(2, "{red}%s{eoc}", ERROR_KEY);
	if (tcsetattr(0, TCSANOW, &term_orig) == -1)
		ft_fprintf(2, "{red}%s{eoc}", "TCSETATTR EPIC FAIL");
	exit(-1);
}
