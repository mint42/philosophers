#include "error.h"
#include "philosophers.h"
#include "struct_thread_data.h"
#include "struct_state.h"
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

void		*instructions(void *data)
{
	struct s_state			*cur_state;
//	struct s_phil			*phil;
//	struct s_fork			*lfork;
//	struct s_fork			*rfork;

	cur_state = ((struct s_thread_data *)(data))->state;
	return (cur_state);
//	phil = &(cur_state->phils[((struct s_thread_data *)(data))->phil_id]);
//	rfork = &(cur_state->forks[((struct s_thread_data *)(data))->phil_id - 1]);
//	lfork = &(cur_state->forks[(((struct s_thread_data *)(data))->phil_id == cur_state->n_phils) ? ((struct s_thread_data *)(data))->phil_id : 0]);
//	while (is_dead(phil) == FALSE)
//	{
//		if (is_fork_in_use(lfork) == FALSE && is_fork_in_use(rfork) == FALSE)
//		{
//			eat(phil);
//			if (is_full(phil) == TRUE)
//			{
//				print(id, FULL);
//				if (does_being_full_matter == TRUE)
//					break ;
//			}
//		}
//		sleep(phil);
//	}
//	print(id, DEAD);
}

int				run_simulation(struct s_state *state)
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
	while (are_end_conds_met(state) == FALSE)
		;
	return (SUCCESS);
}
