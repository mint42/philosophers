#ifndef STRUCT_STATE_H
# define STRUCT_STATE_H

struct s_fork;
struct s_phil;

/*
**	n_phils						number of philosophers
**	tt_die						death counter starting when phil eats (ms)
**	tt_eat						time takes phil to eat (ms)
**	tt_sleep					time takes phil to sleep (ms)
**	use_full_condition			was optional arg (n_meals_to_be_full) given
**	n_meals_to_be_full			set if given, else 0
**	n_phils_full				number of phils currently full
**	n_phils_dead				number of phils currently dead
**	forks						array of forks size [n_phils]
**	phils						array of phils size [n_phils]
*/

struct					s_state
{
	unsigned int		n_phils;
	unsigned int		tt_die;
	unsigned int		tt_eat;
	unsigned int		tt_sleep;
	unsigned int		use_full_condition;
	unsigned int		n_meals_to_be_full;
	unsigned int		n_phils_full;
	unsigned int		n_phils_dead;
	struct s_fork		*forks;
	struct s_phil		*phils;
};

int						setup_state(struct s_state *state, int argc, char **argv);
void					cleanup_state(struct s_state *state);

int						are_end_conds_met(struct s_state *state);

#endif