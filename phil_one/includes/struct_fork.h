#ifndef STRUCT_FORK_H
# define STRUCT_FORK_H

/*
**	setup	-> constructor(initializes/creates insides)
**	cleanup	-> destructor (restores/destroys insides)
**	create	-> wrapper constructor (allocates instance. calls setup)
**	destroy	-> wrapper destructor (frees instance. calls cleanup)
**
**
**	always use unsigned types when dealing with something that should be unsigned
**	TRUE 1, FALSE 0, SUCCESS 1, ERROR 0
**	what happens if in c++ string = string2 assignment fails, or other construction failures?
*/

/*
**	in_use			true or false
*/

struct				s_fork
{
	char			in_use;
};

void				setup_fork(struct s_fork *fork);

int					create_forks(struct s_fork **forks, unsigned int n_forks);
void				destroy_forks(struct s_fork **forks);

#endif
