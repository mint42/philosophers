#ifndef STRUCT_MONASTERY
# define STRUCT_MONASTERY

# include "struct_phil.h"
# include "struct_fork.h"

/*
**	n_phils			number of philosophers
**	tt_die			death countdown starting when you begin eating (ms)
**	tt_eat			time takes to eat (ms)
**	tt_sleep		time takes to sleep (ms)
**	n_x_phils_eat	optional end if all phils have eaten [this] many meals
**	phils			array of phils
**	forks			array of forks
*/

struct				s_monastery
{
	unsigned int	n_phils;
	unsigned int	tt_die;
	unsigned int	tt_eat;
	unsigned int	tt_sleep;
	unsigned int	n_x_phils_eat;
	struct s_phil	*phils;
	struct s_fork	*forks;
};

int					setup_monastery(struct s_monastery *mon, int argc,
							char **argv);

#endif
