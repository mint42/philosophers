#include "error.h"
#include "struct_state.h"
#include "struct_phil.h"
#include <stdlib.h>

void	setup_phil(struct s_phil *phil, unsigned int id, struct s_state *state)
{
	phil->id = id;
	phil->tt_die = state->tt_die;
	phil->tt_eat = state->tt_eat;
	phil->tt_sleep = state->tt_sleep;
	phil->n_x_eaten = 0;
}

int		create_phils(struct s_phil **phils, struct s_state *state)
{
	unsigned int	i;

	*phils = malloc(sizeof(struct s_phil) * state->n_phils);
	if (!*phils)
		return (ERROR);
	i = 0;
	while (i < state->n_phils)
	{
		setup_phil(&((*phils)[i]), i + 1, state);
		++i;
	}
	return (SUCCESS);
}

void	destroy_phils(struct s_phil **phils)
{
	if (*phils)
		free(*phils);
	*phils = 0;
}
