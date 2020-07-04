#include "error.h"
#include "struct_fork.h"
#include <stdlib.h>
#include <pthread.h>

int		setup_fork(struct s_fork *fork)
{
	fork->is_in_use = 0;
	if (pthread_mutex_init(&(fork->lock), NULL) != 0)
		return(ERROR);
	return (SUCCESS);
}

int		cleanup_fork(struct s_fork *fork)
{
	if (pthread_mutex_destroy(&(fork->lock)) != 0)
		return (ERROR);
	return (SUCCESS);
}

void	fork_be_grabbed(struct s_fork *fork)
{
	fork->is_in_use = 1;
	pthread_mutex_lock(&(fork->lock));
}

void	fork_be_dropped(struct s_fork *fork)
{
	fork->is_in_use = 0;
	pthread_mutex_unlock(&(fork->lock));
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
		if (setup_fork(&((*forks)[i])) == ERROR)
			return (ERROR);
		++i;
	}
	return (SUCCESS);
}

int		destroy_forks(struct s_fork **forks, unsigned int n_forks)
{
	unsigned int	i;

	if (!*forks)
		return (ERROR);
	i = 0;
	while (i < n_forks)
	{
		if (cleanup_fork(&((*forks)[i])) == ERROR)
			return (ERROR);
		++i;
	}
	if (*forks)
		free(*forks);
	*forks = 0;
	return (SUCCESS);
}
