#ifndef STRUCT_FORK_H
# define STRUCT_FORK_H

# include <pthread.h>

/*
**	setup	-> constructor(initializes/creates insides)
**	cleanup	-> destructor (restores/destroys insides)
**	create	-> wrapper constructor (allocates instance. calls setup)
**	destroy	-> wrapper destructor (frees instance. calls cleanup)
**
**	always use unsigned types when dealing with something that should be unsigned
**	TRUE 1, FALSE 0, SUCCESS 1, ERROR 0
**	what happens if in c++ string = string2 assignment fails, or other construction failures?
*/

/*
**	in_use			true or false
*/

struct		s_fork
{
	pthread_mutex_t		lock;
	char				is_in_use;
};

int			setup_fork(struct s_fork *fork);
int			cleanup_fork(struct s_fork *fork);
void		fork_be_grabbed(struct s_fork *fork);
void		fork_be_dropped(struct s_fork *fork);

int			create_forks(struct s_fork **forks, unsigned int n_forks);
int			destroy_forks(struct s_fork **forks, unsigned int n_forks);

#endif
