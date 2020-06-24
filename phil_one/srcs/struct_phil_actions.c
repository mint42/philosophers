#include "philosophers.h"
#include "struct_state.h"
#include "struct_phil.h"
#include "struct_fork.h"
#include <unistd.h>
#include <stdbool.h>

void			phil_eat(struct s_phil *phil, const struct s_state *state)
{
	unsigned int	start_time;

	start_time = tod();
	phil_print_action(phil, E_EATING);
	while (((tod() - start_time) < state->ttt_eat) && phil->is_dead == false)
	{
		phil_live(phil, state);
	}
	if (phil->is_dead == true)
		return ;
	phil->time_of_meal = start_time;
	++(phil->n_x_eaten);
	if (phil->n_x_eaten == state->n_meals_full)
		phil->is_full = true;
}

void			phil_sleep(struct s_phil *phil, const struct s_state *state)
{
	unsigned int	start_time;
	
	start_time = tod();
	phil_print_action(phil, E_SLEEPING);
	while (((tod() - start_time) < state->ttt_sleep) && phil->is_dead == false)
	{
		phil_live(phil, state);
	}
}

void			phil_think(struct s_phil *phil)
{
	phil_print_action(phil, E_THINKING);
}

static void		phil_grab_fork(struct s_phil *phil, unsigned int fork_id, const struct s_state *state)
{
	struct s_fork	*fork;

	fork = phil->forks[fork_id];
	while (fork->is_in_use == true && phil->is_dead == false)
	{
		phil_live(phil, state);
	}
	if (phil->is_dead == true)
		return ;
	fork_be_grabbed(fork);
	phil_print_action(phil, E_FORK);
}

void			phil_grab_forks(struct s_phil *phil, const struct s_state *state)
{
	if (state->n_phils == 1)
	{
		while (phil->is_dead == false)
			phil_live(phil, state);
		return ;
	}
	phil_grab_fork(phil, 0, state);
	if (phil->is_dead == true)
		return ;
	phil_grab_fork(phil, 1, state);
	if (phil->is_dead == true)
		return ;
	return ;
}

void			phil_drop_forks(struct s_phil *phil)
{
	fork_be_dropped(phil->forks[0]);
	fork_be_dropped(phil->forks[1]);
//	phil->forks[0] = NULL;
//	phil->forks[1] = NULL;
}

void			phil_live(struct s_phil *phil, const struct s_state *state)
{
	if ((tod() - phil->time_of_meal) >= state->ttt_die)
	{
		phil->is_dead = true;
		phil_print_action(phil, E_DEAD);
	}
	usleep(3);
}
