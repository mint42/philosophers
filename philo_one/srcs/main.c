#include "philosophers.h"
#include "error.h"
#include "struct_state.h"
#include <unistd.h>

static void		print_usage(void)
{
	write(1, "./philo_one number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]\n", 117);
	write(1, "\n", 1);

	write(1, "number_of_philosophers:\n", 24);
	write(1, "\tNumber of philosophers and also number of forks.\n", 50);

	write(1, "time_to_die: (in milliseconds)\n", 31);
	write(1, "\tTime it takes for a philosopher to die.\n", 41);
	write(1, "\tAssuming a death countdown of [x]ms is reset everytime they\n", 61);
	write(1, "\tstart a meal, and at the beginning of every simulation.\n", 57);

	write(1, "time_to_eat: (in milliseconds)\n", 31);
	write(1, "\tTime it takes for a philosopher to eat.\n", 41);

	write(1, "time_to_sleep: (in milliseconds)\n", 33);
	write(1, "\tTime it takes for a philosopher to sleep.\n", 43);

	write(1, "number_of_times_each_philosopher_must_eat: -OPTIONAL-\n", 54);
	write(1, "\tIf all philosophers eat [x] meals, then the simulation ends.\n", 62);
	write(1, "\tElse, it will continue until the death of a philosopher.\n", 58);
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
	if (cleanup_state(&state) == ERROR)
		return (1);
	return (0);
}
