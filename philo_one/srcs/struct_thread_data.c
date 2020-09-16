#include "error.h"
#include "struct_thread_data.h"
#include "struct_state.h"
#include "struct_philo.h"
#include <stdlib.h>

static void		setup_thread_data(struct s_thread_data *data, unsigned int id, struct s_state *state)
{
	data->pthread = 0;
	data->id = id;
	data->state = state;
}

int			create_thread_datas(struct s_thread_data **tdatas, struct s_state *state)
{
	unsigned int	i;

	*tdatas = malloc(sizeof(struct s_thread_data) * state->n_philos);
	if (!*tdatas)
		return (ERROR);
	i = 0;
	while (i < state->n_philos)
	{
		setup_thread_data(&((*tdatas)[i]), i + 1, state);
		++i;
	}
	return (SUCCESS);
}

void		destroy_thread_datas(struct s_thread_data **datas)
{
	if (*datas)
		free(*datas);
	*datas = 0;
}
