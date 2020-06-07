#include "philosophers.h"
#include "error.h"
#include "utils.h"
#include "struct_monastery.h"
#include "struct_phil.h"
#include "struct_fork.h"
#include <stdlib.h>

int		setup_monastery(struct s_monastery *mon, int argc, char **argv)
{
	if (util_atoui(&(mon->n_phils), argv[1]) == ERROR)
		return (ERROR);
	if (util_atoui(&(mon->tt_die), argv[2]) == ERROR)
		return (ERROR);
	if (util_atoui(&(mon->tt_eat), argv[3]) == ERROR)
		return (ERROR);
	if (util_atoui(&(mon->tt_sleep), argv[4]) == ERROR)
		return (ERROR);
	if (argc == NUM_NEEDED_ARGS + 2)
	{
		if (util_atoui(&(mon->n_x_phils_eat), argv[5]) == ERROR)
			return (ERROR);
	}
	if (setup_phils(&(mon->phils), mon) == ERROR)
		return (ERROR);
	if (setup_forks(&(mon->forks), mon->n_phils) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

void	destroy_monastery(struct s_monastery *mon)
{
	destroy_phils(&(mon->phils));
	destroy_forks(&(mon->forks));
}
