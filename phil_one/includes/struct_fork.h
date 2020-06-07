#ifndef STRUCT_FORK
# define STRUCT_FORK

/*
**	location		the philosopher's ID, or 0 if at the center
**	in_use			true or false
*/

struct				s_fork
{
	unsigned int	location;
	char			in_use;
};

int					setup_forks(struct s_fork **forks, unsigned int n_forks);
void				destroy_forks(struct s_fork **forks);

#endif
