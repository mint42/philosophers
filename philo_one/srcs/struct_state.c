#include "philosophers.h"
#include "error.h"
#include "utils.h"
#include "struct_state.h"
#include "struct_fork.h"
#include "struct_philo.h"
#include <stdbool.h>

int		setup_state(struct s_state *state, int argc, char **argv)
{
	if (util_atoui(&(state->n_philos), argv[1]) == ERROR)
		return (ERROR);
	if (util_atoui(&(state->ttt_die), argv[2]) == ERROR)
		return (ERROR);
	if (util_atoui(&(state->ttt_eat), argv[3]) == ERROR)
		return (ERROR);
	if (util_atoui(&(state->ttt_sleep), argv[4]) == ERROR)
		return (ERROR);
	if (argc == (NUM_ARGS_ALLOWED + 1))
	{
		if (util_atoui(&(state->n_meals_full), argv[5]) == ERROR)
			return (ERROR);
		if (state->n_meals_full == 0)
			return (ERROR);
		state->use_full_condition = true;
	}
	else
		state->use_full_condition = false;
	state->n_philos_full = 0;
	state->is_philo_dead = false;
	state->is_sim_ready = false;
	if (create_forks(&(state->forks), state->n_philos) == ERROR)
		return (ERROR);
	if (create_philos(&(state->philos), state) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

int		cleanup_state(struct s_state *state)
{
	destroy_philos(&(state->philos));
	if (destroy_forks(&(state->forks), state->n_philos) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

int		are_end_conds_met(struct s_state *cur_state)
{
	if (cur_state->is_philo_dead == true)
		return (true);
	if (cur_state->use_full_condition == true && cur_state->n_philos_full == cur_state->n_philos)
		return (true);
	return (false);
}
