#include "philosophers.h"
#include "error.h"
#include "struct_state.h"
#include "struct_phil.h"
#include "struct_fork.h"
#include "utils.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

void	setup_phil(struct s_phil *phil, unsigned int id, struct s_state *state)
{
	phil->id = id;
	phil->n_x_eaten = 0;
	phil->is_full = false;
	phil->is_dead = false;
	phil->forks[0] = &(state->forks[id - 1]);
	phil->forks[1] = &(state->forks[(id < state->n_phils) ? id : 0]);
}


void	phil_print_status(struct s_phil *phil, enum e_status s)
{
	const char		*stats[6] = {
		"is thinking",
		"is sleeping",
		"is eating",
		"is full",
		"is dead"
		"has taken a fork",
	};
	char				buf[512];
	unsigned int		len;
	unsigned int		tmp_len;

	len = 0;
	util_uitoa(buf, tod(), 11, &tmp_len);
	len = len + tmp_len;
	buf[len++] = ' ';
	util_uitoa(buf + len, phil->id, 0, &tmp_len);
	len = len + tmp_len;
	buf[len++] = ' ';
	util_strcpy(buf + len, actions[ac], &tmp_len);
	len = len + tmp_len;
	buf[len++] = '\n';
	write(STDOUT_FILENO, buf, len);
}

int		create_phils(struct s_phil **phils, const struct s_state *state)
{
	unsigned int	i;

	*phils = malloc(sizeof(struct s_phil) * state->n_phils);
	if (!*phils)
		return (ERROR);
	i = 0;
	while (i < state->n_phils)
	{
		setup_phil(&((*phils)[i]), i + 1, state);
		++i;
	}
	return (SUCCESS);
}

void	destroy_phils(struct s_phil **phils)
{
	if (*phils)
		free(*phils);
	*phils = 0;
}
