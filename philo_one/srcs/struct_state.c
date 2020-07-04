#include "philosophers.h"
#include "error.h"
#include "utils.h"
#include "struct_state.h"
#include "struct_fork.h"
#include "struct_philo.h"

int		setup_state(struct s_state *state, int argc, char **argv)
{
	if (util_atoui(&(state->n_philos), argv[1]) == ERROR)
		return (ERROR);
	if (util_atoui(&(state->tt_die), argv[2]) == ERROR)
		return (ERROR);
	if (util_atoui(&(state->tt_eat), argv[3]) == ERROR)
		return (ERROR);
	if (util_atoui(&(state->tt_sleep), argv[4]) == ERROR)
		return (ERROR);
	state->n_meals_full = 0;
	if (argc == (NUM_ARGS_ALLOWED + 1))
	{
		if (util_atoui(&(state->n_meals_full), argv[5]) == ERROR)
			return (ERROR);
		if (state->n_meals_full == 0)
			return (ERROR);
	}
	if (create_forks(&(state->forks), state->n_philos) == ERROR)
		return (ERROR);
	if (create_philos(&(state->philos), state) == ERROR)
		return (ERROR);
	state->n_philos_full = 0;
	state->quit = 0;
	state->is_sim_ready = 0;
	return (SUCCESS);
}

int		cleanup_state(struct s_state *state)
{
	destroy_philos(&(state->philos));
	if (destroy_forks(&(state->forks), state->n_philos) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
