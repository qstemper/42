#include "rt.h"

static int	ft_blank(char c)
{
	if (c == '\t' || c == ' ')
		return (1);
	return (0);
}

static int	indent_count(char *line, int nb_line)
{
	int	i;

	i = 0;
	while (ft_blank(line[i]))
	{
		if (line[i] != '\t')
		{
			ft_printf("{cyan}Line %d :{eoc}\t{red}%s{eoc}\n", \
				MSG_INDENT);
			exit(1);
		}
		i++;
	}
	return (i);
}

char		*remove_com(char *line)
{
	char	*curr;

	curr = line;
	while (*curr)
	{
		if (*curr == COMMENT)
		{
			*curr = 0;
			return (line);
		}
		curr++;
	}
	return (line);
}

int		is_empty(char *line)
{
	while (*line)
	{
		if (!ft_blank(*line))
			return (0);
		line++;
	}
	return (1);
}

void			check_cmd(int indent_lvl, t_pars *pars, \
	char **cmd_line, int line)
{
	t_pars_cmd	*command;

	cmd = pars->cmd;
	while (cmd)
	{
		if (indent_lvl == cmd->indent_lvl && \
			ft_strequ(cmd->tok, *cmd_line))
		{
			cmd->callback(pars, cmd_line + 1);
			return ;
		}
		cmd = cmd_next;
	}
	ft_printf("{cyan}Line %d :\t{red}%s :{eoc} {yellox}%s{eoc}\n", \
		line, MSG_CMD, cmd_line[0]);
}
