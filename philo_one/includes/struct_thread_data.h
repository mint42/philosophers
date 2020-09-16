#ifndef STRUCT_THREAD_DATA_H
# define STRUCT_THREAD_DATA_H

# include "struct_state.h"
# include "struct_philo.h"
# include "struct_fork.h"
# include <pthread.h>

/*
**	thread			pthread ID
**	philo_id		which philo is this thread attached to
**	cur_state		current state of the simulation
*/

struct					s_thread_data
{
	pthread_t			pthread;
	unsigned int		id;
	struct s_state		*state;
};

int						create_thread_datas(struct s_thread_data **datas, struct s_state *state);
void					destroy_thread_datas(struct s_thread_data **datas);

#endif
