#include "error.h"
#include "struct_monastery.h"
#include "struct_phil.h"
#include "struct_fork.h"
#include <stdlib.h>


static void		setup_fork(struct s_fork *fork, unsigned int location)
{
	fork->location = location;
	fork->in_use = 0;
}

int				setup_forks(struct s_fork **forks, unsigned int n_forks)
{
	unsigned int	i;

	*forks = malloc(sizeof(struct s_fork) * n_forks);
	if (!*forks)
		return (ERROR);
	i = 0;
	while (i < n_forks)
	{
		setup_fork(&((*forks)[i]), i + 1);
		++i;
	}
	return (SUCCESS);
}

void			destroy_forks(struct s_fork **forks)
{
	free(*forks);
	*forks = 0;
}
