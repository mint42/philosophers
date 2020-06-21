#include "error.h"
#include "struct_fork.h"
#include <stdlib.h>
#include <stdbool.h>

void	setup_fork(struct s_fork *fork)
{
	fork->is_in_use = false;
}

void	fork_be_grabbed(struct s_fork *fork)
{
	(void)fork;
	////pthread_mutex_lock(fork);
}

void	fork_be_dropped(struct s_fork *fork)
{
	(void)fork;
	//pthread_mutex_unlock(fork);
}

int		create_forks(struct s_fork **forks, unsigned int n_forks)
{
	unsigned int	i;

	*forks = malloc(sizeof(struct s_fork) * n_forks);
	if (!*forks)
		return (ERROR);
	i = 0;
	while (i < n_forks)
	{
		setup_fork(&((*forks)[i]));
		++i;
	}
	return (SUCCESS);
}

void	destroy_forks(struct s_fork **forks)
{
	if (*forks)
		free(*forks);
	*forks = 0;
}
