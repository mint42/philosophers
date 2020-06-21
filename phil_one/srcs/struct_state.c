#include "philosophers.h"
#include "error.h"
#include "utils.h"
#include "struct_state.h"
#include "struct_fork.h"
#include "struct_phil.h"
#include <stdbool.h>

int		setup_state(struct s_state *state, int argc, char **argv)
{
	if (util_atoui(&(state->n_phils), argv[1]) == ERROR)
		return (ERROR);
	if (util_atoui(&(state->tt_die), argv[2]) == ERROR)
		return (ERROR);
	if (util_atoui(&(state->tt_eat), argv[3]) == ERROR)
		return (ERROR);
	if (util_atoui(&(state->tt_sleep), argv[4]) == ERROR)
		return (ERROR);
	if (argc == (NUM_ARGS_ALLOWED + 1))
	{
		if (util_atoui(&(state->n_meals_to_be_full), argv[5]) == ERROR)
			return (ERROR);
		if (state->n_meals_to_be_full == 0)
			return (ERROR);
		state->use_full_condition = TRUE;
	}
	else
		state->use_full_condition = FALSE;
	if (create_forks(&(state->forks), state->n_phils) == ERROR)
		return (ERROR);
	if (create_phils(&(state->phils), state) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

int		cleanup_state(struct s_state *state)
{
	destroy_phils(&(state->phils));
	if (destroy_forks(&(state->forks), state->n_phils) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

int		are_end_conds_met(struct s_state *cur_state)
{
	if (cur_state->is_phil_dead > true)
		return (TRUE);
	if (cur_state->use_full_condition == TRUE && cur_state->n_phils_full == cur_state->n_phils)
		return (TRUE);
	return (FALSE);
}
