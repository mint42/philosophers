#ifndef STRUCT_STATE_H
# define STRUCT_STATE_H

struct s_fork;
struct s_philo;

/*
**	quit			quit the simulation? TRUE/FALSE
**						- are any philosophers dead?
**						- are all philosophers full?
**	is_sim_ready	is the simulation ready to be run? TRUE/FALSE
**						- have init conditions been setup?
**	tt_eat			total time it takes a philosopher [time to] eat
**	tt_sleep		total time it takes a philosopher [time to] sleep
**	tt_die			total time it takes a philosopher [time to] die
**						- death counter resets after every meal
**	use_full		was optional argument [n_meals_full] given
**	n_meals_full	number of meals needed for a philosopher to be full
						- set if [n_meals_full] was given, else 0
**	n_philos_full	number of philosophers currently full
**	n_philos		number of philosophers. also the number of forks
**	forks			array of forks. size: [n_philos]
**	philos			array of philosophers. size: [n_philos]
*/

struct					s_state
{
	char				quit;
	char				is_sim_ready;
	unsigned int		tt_die;
	unsigned int		tt_eat;
	unsigned int		tt_sleep;
	char				use_full;
	unsigned int		n_meals_full;
	unsigned int		n_philos_full;
	unsigned int		n_philos;
	struct s_fork		*forks;
	struct s_philo		*philos;
};

int						setup_state(struct s_state *state, int argc, char **argv);
int						cleanup_state(struct s_state *state);

int						are_end_conds_met(struct s_state *state);

#endif
