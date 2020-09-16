#include "philosophers.h"
#include "utils.h"
#include "struct_state.h"
#include "struct_philo.h"
#include "struct_fork.h"
#include <unistd.h>

void			philo_eat(struct s_philo *philo, const struct s_state *state)
{
	unsigned int		start_time;
	unsigned int		tt_eat;

	tt_eat = state->tt_eat;
	start_time = util_tod();
	philo_print_action(philo, E_EATING, state);
	while ((util_tod() - start_time < tt_eat) && !philo->is_dead && !state->quit)
	{
		philo_live(philo, state);
	}
	if (philo->is_dead || state->quit)
		return ;
	philo->time_of_meal = start_time;
	++(philo->n_meals_eaten);
	if (philo->n_meals_eaten == state->n_meals_full)
		philo->is_full = 1;
}

void			philo_sleep(struct s_philo *philo, const struct s_state *state)
{
	unsigned int		start_time;
	unsigned int		tt_sleep;
	
	tt_sleep = state->tt_sleep;
	start_time = util_tod();
	philo_print_action(philo, E_SLEEPING, state);
	while ((util_tod() - start_time < tt_sleep) && !philo->is_dead && !state->quit)
	{
		philo_live(philo, state);
	}
}

void			philo_think(struct s_philo *philo, const struct s_state *state)
{
	philo_print_action(philo, E_THINKING, state);
}

static void		philo_grab_fork(struct s_philo *philo, unsigned int fork_id, const struct s_state *state)
{
	struct s_fork	*fork;

	fork = philo->forks[fork_id];
	while (fork->is_in_use && !philo->is_dead && !state->quit)
	{
		philo_live(philo, state);
	}
	if (philo->is_dead || state->quit)
		return ;
	fork_be_grabbed(fork);
	philo_print_action(philo, E_FORK, state);
}

void			philo_grab_forks(struct s_philo *philo, const struct s_state *state)
{
	if (state->n_philos == 1)
	{
		while (!philo->is_dead && !state->quit)
		{
			philo_live(philo, state);
		}
		return ;
	}
	philo_grab_fork(philo, 0, state);
	if (philo->is_dead || state->quit)
		return ;
	philo_grab_fork(philo, 1, state);
}

void			philo_drop_forks(struct s_philo *philo)
{
	fork_be_dropped(philo->forks[0]);
	fork_be_dropped(philo->forks[1]);
}

void			philo_live(struct s_philo *philo, const struct s_state *state)
{
	if ((int)state->tt_die - ((int)util_tod() - (int)philo->time_of_meal) <= 0)
	{
		philo->is_dead = 1;
		philo_print_action(philo, E_DEAD, state);
	}
	usleep(3);
}
