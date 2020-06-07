#ifndef STRUCT_PHIL
# define STRUCT_PHIL

/*
**	phil_id			mostly for positioning puposes. philosopher id
**	tt_die			death countdown starting when you begin eating (ms)
**	tt_eat			time takes to eat (ms)
**	tt_sleep		time takes to sleep (ms)
**	n_x_eaten		# meals eaten 
*/

struct				s_monastery;

struct				s_phil
{
	unsigned int	phil_id;
	unsigned int	tt_die;
	unsigned int	tt_eat;
	unsigned int	tt_sleep;
	unsigned int	n_x_eaten;
};

int					setup_phils(struct s_phil **phils, struct s_monastery *mon);
void				destroy_phils(struct s_phil **phils);

#endif
