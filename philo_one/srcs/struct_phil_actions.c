#include "philosophers.h"
#include "struct_state.h"
#include "struct_philo.h"
#include "struct_fork.h"
#include <unistd.h>
#include <stdbool.h>

void			philo_eat(struct s_philo *philo, const struct s_state *state)
{
	unsigned int	start_time;

	start_time = tod();
	philo_print_action(philo, E_EATING);
	while (((tod() - start_time) < state->ttt_eat) && philo->is_dead == false)
	{
		philo_live(philo, state);
	}
	if (philo->is_dead == true)
		return ;
	philo->time_of_meal = start_time;
	++(philo->n_x_eaten);
	if (philo->n_x_eaten == state->n_meals_full)
		philo->is_full = true;
}

void			philo_sleep(struct s_philo *philo, const struct s_state *state)
{
	unsigned int	start_time;
	
	start_time = tod();
	philo_print_action(philo, E_SLEEPING);
	while (((tod() - start_time) < state->ttt_sleep) && philo->is_dead == false)
	{
		philo_live(philo, state);
	}
}

void			philo_think(struct s_philo *philo)
{
	philo_print_action(philo, E_THINKING);
}

static void		philo_grab_fork(struct s_philo *philo, unsigned int fork_id, const struct s_state *state)
{
	struct s_fork	*fork;

	fork = philo->forks[fork_id];
	while (fork->is_in_use == true && philo->is_dead == false)
	{
		philo_live(philo, state);
	}
	if (philo->is_dead == true)
		return ;
	fork_be_grabbed(fork);
	philo_print_action(philo, E_FORK);
}

void			philo_grab_forks(struct s_philo *philo, const struct s_state *state)
{
	if (state->n_philos == 1)
	{
		while (philo->is_dead == false)
			philo_live(philo, state);
		return ;
	}
	philo_grab_fork(philo, 0, state);
	if (philo->is_dead == true)
		return ;
	philo_grab_fork(philo, 1, state);
}

void			philo_drop_forks(struct s_philo *philo)
{
	fork_be_dropped(philo->forks[0]);
	fork_be_dropped(philo->forks[1]);
//	philo->forks[0] = NULL;
//	philo->forks[1] = NULL;
}

void			philo_live(struct s_philo *philo, const struct s_state *state)
{
	if ((tod() - philo->time_of_meal) >= state->ttt_die)
	{
		philo->is_dead = true;
		philo_print_action(philo, E_DEAD);
	}
	usleep(3);
}