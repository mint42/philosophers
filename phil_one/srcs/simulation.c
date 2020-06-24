#include "error.h"
#include "philosophers.h"
#include "struct_thread_data.h"
#include "struct_state.h"
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <sys/time.h>

unsigned int	tod(void)
{
	struct timeval	tp;

	gettimeofday(&tp, NULL);
	return ((tp.tv_sec * 1000) + (tp.tv_usec / 1000));
}

void			*instructions(void *data)
{
	struct s_state			*state;
	struct s_phil			*phil;

	state = ((struct s_thread_data *)data)->state;
	phil = &(state->phils[((struct s_thread_data *)data)->id - 1]);
	while (phil->is_dead == false && state->is_phil_dead == false)
	{
		phil_think(phil);
		phil_grab_forks(phil, state);
		if (phil->is_dead == true)
			break ;
		phil_eat(phil, state);
		phil_drop_forks(phil);
		if (phil->is_full == true)
		{
			++(state->n_phils_full);
			break ;
		}
		phil_sleep(phil, state);
	}
	return (NULL);
}

int					run_simulation(struct s_state *state)
{
	struct s_thread_data	*tdatas;
	unsigned int			i;

	if (create_thread_datas(&tdatas, state) == ERROR)
		return (ERROR);
	i = 0;
	while (i < state->n_phils)
	{
		pthread_create(&((tdatas[i]).pthread), NULL, &instructions, (void *)&(tdatas[i]));
		++i;
	}
	while (are_end_conds_met(state) == false)
		;
	destroy_thread_datas(&tdatas);	
	return (SUCCESS);
}
