#ifndef STRUCT_PHIL_H
# define STRUCT_PHIL_H

struct				s_state;

enum				e_action
{
	E_THINKING,
	E_SLEEPING,
	E_EATING,
	E_FULL,
	E_DEAD,
	E_FORK,
};

/*
**	is_dead			TRUE/FALSE dead
**	is_full			TRUE/FALSE full
**	id				philosopher id and can be reference for forks in philo_one
**	n_meals_eaten	number of meals eaten
**	time_of_meal	time since starting last meal
**	*forks[2]		two fork pointers. one fork for each hand
*/

struct					s_philo
{
	char				is_dead;
	char				is_full;
	unsigned int		id;
	unsigned int		n_meals_eaten;
	unsigned long int	time_of_meal;
	struct s_fork		*forks[2];
};

void					setup_philo(struct s_philo *philo, unsigned int id,
								const struct s_state *state);
int						create_philos(struct s_philo **philos,
								const struct s_state *state);
void					destroy_philos(struct s_philo **philo);

void					philo_print_action(const struct s_philo *philo, enum e_action ac);

/*
**	Actions
*/
void					philo_eat(struct s_philo *philo, const struct s_state *state);
void					philo_sleep(struct s_philo *philo, const struct s_state *state);
void					philo_think(struct s_philo *philo);
void					philo_grab_forks(struct s_philo *philo, const struct s_state *state);
void					philo_drop_forks(struct s_philo *philo);
void					philo_live(struct s_philo *philo, const struct s_state *state);

#endif
