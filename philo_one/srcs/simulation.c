#include "philosophers.h"
#include "error.h"
#include "struct_thread_data.h"
#include "struct_state.h"
#include "struct_philo.h"
#include <pthread.h>

/*
** rinse_repeat() manages the rules for each philosopher in the simultion.
*/

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

/*
** instructions() manages each individual thread, which in this case means it's
** in control of one of the philosophers actions. first it unpacks the data
** sent in by the void pointer, and once all of the threads are set up,
** indicated by the is_sim_ready variable, it loops in a rinse & repeat
** function that controls its sleeping/eating/thinking states.
** if end conditions are met then it also updates the state variable before
** quitting.
*/

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
	if (philo->is_dead || 
		(philo->is_full && ++(state->n_philos_full) == state->n_philos))
		state->quit = 1;
	return (NULL);
}

/*
** run_simulation() creates structs to store information for each thread. those
** threads are then created and managed by the instructions() subroutine.
** (see above). the simulation loops until an end condition is met, and data
** is destroyed.
*/

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
