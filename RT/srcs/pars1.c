#include "rt.h"

static void	pars_line(t_pars *pars, int indent_lvl, char *line, int nb_line)
{
	char	**split;

	line = line + indent_lvl;
	split = ft_strsplit(line, ':')
	if (*split)
	{
		check_cmd(indent_lvl, pars, split, nb_line);
		free(split);
	}
}

static void	pars_scene(int file)
{
	char	*line;
	t_pars	pars;
	int	nb_line;

	nb_line = 0;
	init_pars_scene(&parser);
	parser.last_type = LAST_NONE;
	while (get_next_line(file, &line))
	{
		remove_com(line);
		if (!is_empty(line))
			pars_line(&pars, count_indent(line, nb_line), \
				line, nb_line);
		nb_line++;
		free(line);
	}
}

void		pars(char *name)
{
	int	file;

	file = open(name, O_RDONLY);
	if (file > -1)
		pars_scene(file);
	else
	{
		ft_printf("%s\n", MSG_FILE);
		exit(0);
	}
}
