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
	phil->tt_die = state->tt_die;
	phil->tt_eat = state->tt_eat;
	phil->tt_sleep = state->tt_sleep;
	phil->n_x_eaten = 0;
	phil->is_full = false;
	phil->is_dead = false;
	phil->forks[0] = &(state->forks[id - 1]);
	phil->forks[1] = &(state->forks[(id < state->n_phils) ? id : 0]);
}

# define TIME 69420

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
	util_uitoa(buf, TIME, 6, &tmp_len);
	len = len + tmp_len;
	buf[len] = ' ';
	util_uitoa(buf + len, phil->id, 0, &tmp_len);
	len = len + tmp_len;
	buf[len] = ' ';
	util_strcpy(buf + len, stats[s], &tmp_len);
	len = len + tmp_len;
	buf[len] = '\n';
	write(STDOUT_FILENO, buf, len);
}

void	phil_eat(struct s_phil *phil)
{
	++(phil->n_x_eaten);
	phil_print_status(phil, E_EATING);
}

void	phil_sleep(struct s_phil *phil)
{
	phil_print_status(phil, E_SLEEPING);
}

void	phil_think(struct s_phil *phil)
{
	phil_print_status(phil, E_THINKING);
}

void	phil_grab_fork(struct s_phil *phil, struct s_fork *fork, struct s_state *state)
{
	while (fork->is_in_use == true && phil->is_dead == false)
		phil_live(phil);
	if (phil->is_dead == true)
	{
		phil_die(phil, state);
		return ;
	}
	fork_be_grabbed(fork);
	phil_print_status(phil, E_FORK);
}

void	phil_grab_forks(struct s_phil *phil, struct s_state *state)
{
	phil_grab_fork(phil, phil->forks[0], state);
	if (phil->is_dead == true)
		return ;
	phil_grab_fork(phil, phil->forks[1], state);
	if (phil->is_dead == true)
		return ;
	return ;
}

void	phil_drop_forks(struct s_phil *phil)
{
	fork_be_dropped(phil->forks[0]);
	fork_be_dropped(phil->forks[1]);
//	phil->forks[0] = NULL;
//	phil->forks[1] = NULL;
}

void	phil_be_full(struct s_phil *phil)
{
	phil->is_full = true;
//	phil_print_status(phil, E_FULL);
}

void	phil_die(struct s_phil *phil, struct s_state *state)
{
	state->is_phil_dead = true;
	phil_print_status(phil, E_DEAD);
}

void	phil_live(struct s_phil *phil)
{
	(void)phil;
}

int		create_phils(struct s_phil **phils, struct s_state *state)
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
