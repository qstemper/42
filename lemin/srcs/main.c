#include "lemin.h"

int		main(int ac, char **av, char **ep)
{
	proginfo_init(ac, av, ep, CS_O);
	lemin(0);
	return (0);
}
