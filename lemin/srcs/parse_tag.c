#include "lemin.h"

int			parse_tag(char *line, int *state)
{
	int		i;

	if (*(line + 1) != LEM_COMMENT_CHAR)
		return (LEM_NOERR);
	if (*state < LEM_DEFAULT_STATE)
		return (LEM_NOPOP_ERR);
	i = -1;
	while (g_cmd[++i].cmd)
	{
		if (!ft_strcmp(line + 2, g_cmd[i].cmd))
			*state = g_cmd[i].state;
	}
	return (LEM_NOERR);
}
