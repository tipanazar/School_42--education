
#include "./philo.h"

int	ft_isnums(char **str)
{
	int	f_idx;
	int	s_idx;

	f_idx = 1;
	while (str[f_idx])
	{
		s_idx = 0;
		while (str[f_idx][s_idx])
		{
			if (str[f_idx][s_idx] > '9' || str[f_idx][s_idx] < '0')
				return (1);
			s_idx++;
		}
		f_idx++;
	}
	return (0);
}

int	ft_check_args(char **argv, t_global *global)
{
	int	idx;

	idx = 0;
	if (ft_isnums(argv))
		return (1);
	while (argv[++idx])
	{
		if (ft_atoi(argv[idx]) <= 0)
			return (1);
	}
	global->num_philo = ft_atoi(argv[1]);
	global->time_to_die = ft_atoi(argv[2]);
	global->time_to_eat = ft_atoi(argv[3]);
	global->time_to_sleep = ft_atoi(argv[4]);
	global->num_times_feed = 0;
	if (argv[5])
		global->num_times_feed = ft_atoi(argv[5]);
	global->num_fed = 0;
	global->go = 1;
	pthread_mutex_init(&global->printf, NULL);
	pthread_mutex_init(&global->checker, NULL);
	pthread_mutex_init(&global->eating, NULL);
	global->locked = 0;
	return (0);
}

void	*start_life(void *arg)
{
	t_person	*philo;

	philo = (t_person *)arg;
	if (philo->global->num_philo == 1)
	{
		philo_print(philo, "has taken a fork", 1);
		ft_custom_sleep(philo->global->time_to_die, philo->global);
	}
	if (philo->global->num_philo > 1 && philo->id % 2)
		ft_custom_sleep(40, philo->global);
	while (get_go(philo->global))
	{
		if (philo->id % 2)
			usleep(100);
		if (philo->global->num_times_feed > 0
			&& philo->counter_fed >= philo->global->num_times_feed)
			break ;
		eating(philo);
		pthread_mutex_unlock(&philo->global->forks[philo->left_hand]);
		pthread_mutex_unlock(&philo->global->forks[philo->right_hand]);
		philo_print(philo, "is sleeping", 1);
		ft_custom_sleep(philo->global->time_to_sleep, philo->global);
		philo_print(philo, "is thinking", 1);
	}
	return (NULL);
}

int	ft_start_philo(t_global *global)
{
	long long	idx;

	global->person = (t_person *)malloc(sizeof(t_person) * global->num_philo);
	if (!global->person)
		return (1);
	global->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* global->num_philo);
	if (!global->forks)
	{
		free(global->person);
		return (1);
	}
	idx = -1;
	while (++idx < global->num_philo)
	{
		if (pthread_mutex_init(&global->forks[idx], NULL))
		{
			free(global->person);
			free(global->forks);
			return (1);
		}
	}
	if (hepler_start_philo(global))
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_global	global;

	if (argc >= 5 && argc <= 6)
	{
		if (ft_check_args(argv, &global))
			return (-1);
		if (ft_start_philo(&global))
			return (-1);
		ft_die_check(&global);
		ft_free_philo(&global);
	}
	return (0);
}
