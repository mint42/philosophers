#ifndef STRUCT_PHIL_H
# define STRUCT_PHIL_H

enum					e_philosopher_options
{
	E_DEAD = 0,
	E_EATING,
	E_SLEEPING,
	E_THINKING,
};

struct					s_state;

/*
**	tt_die			death countdown starting when you begin eating (ms)
**	tt_eat			time takes to eat (ms)
**	tt_sleep		time takes to sleep (ms)
**	n_x_eaten		# meals eaten 
*/

struct					s_phil
{
	unsigned int		id;
	unsigned int		tt_die;
	unsigned int		tt_eat;
	unsigned int		tt_sleep;
	unsigned int		n_x_eaten;
};

void					setup_phil(struct s_phil *phil, unsigned int id, struct s_state *state);

int						create_phils(struct s_phil **phils, struct s_state *state);
void					destroy_phils(struct s_phil **phil);

#endif
