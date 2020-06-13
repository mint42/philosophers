#include "error.h"
#include "philosophers.h"
#include "struct_state.h"
#include <stdio.h>
#include <pthread.h>

static void		print_usage(void)
{
	printf("./phil_one number_of_philosophers time_to_die time_to_eat time_to_sleep [number_times_each_philosopher_must_eat]\n");
	printf("\n");

	printf("number_of_philosophers:\n");
	printf("\tNumber of philosophers and also number of forks.\n");

	printf("time_to_die: (in milliseconds)\n");
	printf("\tTime it takes for a philosopher to die.\n");
	printf("\tAssuming a death countdown of [x]ms is reset everytime they\n");
	printf("\tstart a meal, and at the beginning of every simulation.\n");

	printf("time_to_eat: (in milliseconds)\n");
	printf("\tTime it takes for a philosopher to eat.\n");

	printf("time_to_sleep: (in milliseconds)\n");
	printf("\tTime it takes for a philosopher to sleep.\n");

	printf("number_of_times_each_philosopher_must_eat: -OPTIONAL-\n");
	printf("\tIf all philosophers eat [x] meals, then the simulation ends.\n");
	printf("\tElse, it will continue until the death of a philosopher.\n");
}

int				main(int argc, char **argv)
{
	struct s_state	state;

	if (argc < (NUM_ARGS_NEEDED + 1) || argc > (NUM_ARGS_ALLOWED + 1))
	{
		print_usage();
		return (1);
	}
	if (setup_state(&state, argc, argv) == ERROR)
		return (1);
	if (run_simulation(&state) == ERROR)
		return (1);
	return (0);
}
