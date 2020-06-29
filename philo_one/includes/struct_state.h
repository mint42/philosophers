#ifndef STRUCT_STATE_H
# define STRUCT_STATE_H

struct s_fork;
struct s_philo;

/*
**	n_philos					number of philosophers
**	tt_die						death counter starting when philo eats (ms)
**	tt_eat						time takes philo to eat (ms)
**	tt_sleep					time takes philo to sleep (ms)
**	use_full_condition			was optional arg (n_meals_to_be_full) given
**	n_meals_to_be_full			set if given, else 0
**	n_philos_full				number of philos currently full
**	is_philo_dead				are any philosophers dead? TRUE/FALSE
**	is_sim_ready				is the simulation ready to be run? TRUE/FALSE
**	forks						array of forks size [n_philos]
**	philos						array of philos size [n_philos]
*/

struct					s_state
{
	unsigned int		n_philos;
	unsigned int		ttt_die;
	unsigned int		ttt_eat;
	unsigned int		ttt_sleep;
	unsigned int		use_full_condition;
	unsigned int		n_meals_full;
	unsigned int		n_philos_full;
	unsigned int		is_philo_dead;
	unsigned int		is_sim_ready;
	struct s_fork		*forks;
	struct s_philo		*philos;
};

int						setup_state(struct s_state *state, int argc, char **argv);
int						cleanup_state(struct s_state *state);

int						are_end_conds_met(struct s_state *state);

#endif
