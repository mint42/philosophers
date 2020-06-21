#ifndef STRUCT_PHIL_H
# define STRUCT_PHIL_H

struct					s_state;

/*
**	id				philosopher id and id for forks
**	tt_die			death countdown starting when you begin eating (ms)
**	tt_eat			time takes to eat (ms)
**	tt_sleep		time takes to sleep (ms)
**	n_x_eaten		# meals eaten 
**	is_dead			TRUE/FALSE
**	is_full			TRUE/FALSE
**	*forks[2]		two fork pointers. one for each hand
*/


enum				e_action
{
	E_THINKING,
	E_SLEEPING,
	E_EATING,
	E_FULL,
	E_DEAD,
	E_FORK,
};

struct				s_phil
{
	unsigned int	id;
	unsigned int	n_x_eaten;
	unsigned int	is_dead;
	unsigned int	is_full;
	struct s_fork	*forks[2];
};

void				setup_phil(struct s_phil *phil, unsigned int id,
							const struct s_state *state);
int					create_phils(struct s_phil **phils,
							const struct s_state *state);
void				destroy_phils(struct s_phil **phil);

void				phil_print_action(const struct s_phil *phil, enum e_action ac);

void				phil_eat(struct s_phil *phil);
void				phil_sleep(struct s_phil *phil);
void				phil_think(struct s_phil *phil);
void				phil_grab_forks(struct s_phil *phil, const struct s_state *state);
void				phil_drop_forks(struct s_phil *phil);
void				phil_live(struct s_phil *phil, const struct s_state *state);

#endif
