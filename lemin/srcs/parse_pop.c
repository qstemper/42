#include "lemin.h"

int		parse_pop(char *line, int *state, t_cons *rules)
{
	*state = LEM_DEFAULT_STATE;
	rules->pop = ft_atoi(line);
	return ((rules->pop < 1 ? LEM_SMALLPOP_ERR : LEM_NOERR));
}
