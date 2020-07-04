#include "philosophers.h"
#include "error.h"
#include "struct_state.h"
#include "struct_philo.h"
#include "struct_fork.h"
#include "utils.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

void	setup_philo(struct s_philo *philo, unsigned int id, const struct s_state *state)
{
	philo->id = id;
	philo->n_x_eaten = 0;
	philo->is_full = false;
	philo->is_dead = false;
	philo->forks[0] = &(state->forks[id - 1]);
	if (state->n_philos > 1)
		philo->forks[1] = &(state->forks[(id < state->n_philos) ? id : 0]);
	else
		philo->forks[1] = NULL;
}

void	philo_print_action(const struct s_philo *philo, enum e_action ac)
{
	const char		*actions[6] = {
		"is thinking",
		"is sleeping",
		"is eating",
		"is full",
		"is dead",
		"has taken a fork",
	};
	char				buf[512];
	unsigned int		len;
	unsigned int		tmp_len;

	len = 0;
	util_uitoa(buf, util_tod(), 10, &tmp_len);
	len = len + tmp_len;
	buf[len++] = ' ';
	util_uitoa(buf + len, philo->id, 0, &tmp_len);
	len = len + tmp_len;
	buf[len++] = ' ';
	util_strcpy(buf + len, actions[ac], &tmp_len);
	len = len + tmp_len;
	buf[len++] = '\n';
	write(STDOUT_FILENO, buf, len);
}

int		create_philos(struct s_philo **philos, const struct s_state *state)
{
	unsigned int	i;

	*philos = malloc(sizeof(struct s_philo) * state->n_philos);
	if (!*philos)
		return (ERROR);
	i = 0;
	while (i < state->n_philos)
	{
		setup_philo(&((*philos)[i]), i + 1, state);
		++i;
	}
	return (SUCCESS);
}

void	destroy_philos(struct s_philo **philos)
{
	if (*philos)
		free(*philos);
	*philos = 0;
}
