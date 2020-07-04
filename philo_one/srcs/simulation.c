#include "error.h"
#include "philosophers.h"
#include "struct_thread_data.h"
#include "struct_state.h"
#include "struct_philo.h"
#include <pthread.h>
#include <stdbool.h>

void			*instructions(void *data)
{
	struct s_state			*state;
	struct s_philo			*philo;

	state = ((struct s_thread_data *)data)->state;
	philo = &(state->philos[((struct s_thread_data *)data)->id - 1]);
	while (state->is_sim_ready == false)
		;
	while (philo->is_dead == false && state->is_philo_dead == false)
	{
		philo_think(philo);
		philo_grab_forks(philo, state);
		if (philo->is_dead == true)
			break ;
		philo_eat(philo, state);
		if (philo->is_dead == true)
			break ;
		philo_drop_forks(philo);
		if (philo->is_full == true)
		{
			++(state->n_philos_full);
			break ;
		}
		philo_sleep(philo, state);
	}
	if (philo->is_dead == true)
		state->is_philo_dead = true;
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
	state->is_sim_ready = true;
	while (are_end_conds_met(state) == false)
		;
	destroy_thread_datas(&tdatas);	
	return (SUCCESS);
}
