#include "error.h"
#include "struct_monastery.h"
#include "struct_phil.h"
#include <stdlib.h>

static void		setup_phil(struct s_phil *phil, struct s_monastery *mon,
						unsigned int id)
{
	phil->phil_id = id;
	phil->tt_die = mon->tt_die;
	phil->tt_eat = mon->tt_eat;
	phil->tt_sleep = mon->tt_sleep;
	phil->n_x_eaten = 0;
}

int				setup_phils(struct s_phil **phils, struct s_monastery *mon)
{
	unsigned int	i;

	*phils = malloc(sizeof(struct s_phil) * mon->n_phils);
	if (!*phils)
		return (ERROR);
	i = 0;
	while (i < mon->n_phils)
	{
		setup_phil(&((*phils)[i]), mon, i + 1);
		++i;
	}
	return (SUCCESS);
}

void	destroy_phils(struct s_phil **phils)
{
	free(*phils);
	*phils = 0;
}
