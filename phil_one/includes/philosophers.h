#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# define NUM_ARGS_NEEDED 4
# define NUM_ARGS_ALLOWED 5

# define TRUE 1
# define FALSE 0

struct s_state;

int		run_simulation(struct s_state *state);

#endif
