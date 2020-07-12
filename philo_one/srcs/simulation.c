#include "philosophers.h"
#include "error.h"
#include "struct_thread_data.h"
#include "struct_state.h"
#include "struct_philo.h"
#include <pthread.h>

static void		rinse_repeat(struct s_philo *philo, struct s_state *state)
{
	philo_think(philo);
	philo_grab_forks(philo, state);
	if (philo->is_dead)
		return ;
	philo_eat(philo, state);
	if (philo->is_dead)
		return ;
	philo_drop_forks(philo);
	if (philo->is_full)
		return ;
	philo_sleep(philo, state);
}

void			*instructions(void *data)
{
	struct s_state			*state;
	struct s_philo			*philo;

	state = ((struct s_thread_data *)data)->state;
	philo = &(state->philos[((struct s_thread_data *)data)->id - 1]);
	while (!state->is_sim_ready)
		;
	while (!philo->is_dead && !philo->is_full && !state->quit)
		rinse_repeat(philo, state);
	if (philo->is_dead)
		state->quit = 1;
	else if (philo->is_full && ++(state->n_philos_full) == state->n_philos)
		state->quit = 1;
	return (NULL);
}

int					run_simulation(struct s_state *state)
{
	struct s_thread_data	*tdatas;
	unsigned int			i;

	if (create_thread_datas(&tdatas, state) == ERROR)
		return (ERROR);
	i = 0;
	while (i < state->n_philos)
	{
		pthread_create(&((tdatas[i]).pthread), NULL, &instructions, (void *)&(tdatas[i]));
		++i;
	}
	state->is_sim_ready = 1;
	while (!state->quit)
		;
	destroy_thread_datas(&tdatas);	
	return (SUCCESS);
}
