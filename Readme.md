# PHILOSOPHERS

Philosophers is a systems project in the 42 curriculum. It introduces the concept of concurrent programming, highlighting the use of multi-threading, mutexes, and semaphores. The goal of the project is to simulate a [Dining Philosophers Problem](https://en.wikipedia.org/wiki/Dining_philosophers_problem).

## Getting Started

```
git clone https://github.com/mint42/philosophers
```

Inside the cloned repository are three phil_# folders, which can all be compiled and run separately. For each one there is a Makefile that, when the `make` command is run in that folder, will create an executable.

```
usage: ./phil_# number_of_philosophers time_to_die time_to_eat time_to_sleep [number_times_each_philosopher_must_eat]

number_of_philosophers:
	Number of philosophers and also number of forks.\n");

time_to_die: (in milliseconds)
	Time it takes for a philosopher to die.
	Assuming a death countdown of [x]ms is reset everytime they
	start a meal, and at the beginning of every simulation.

time_to_eat: (in milliseconds)
	Time it takes for a philosopher to eat.

time_to_sleep: (in milliseconds)
	Time it takes for a philosopher to sleep.

number_of_times_each_philosopher_must_eat: -OPTIONAL-
	If all philosophers eat [x] meals, then the simulation ends.
	Else, it will continue until the death of a philosopher.
```

## References 

-

## Author

[Ari Reedy](https://github.com/mint42/)
