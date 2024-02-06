#include "philo.h"

void	philo_take_forks2(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	if (is_alive(philo) == 0)
	{
		pthread_mutex_unlock(philo->left_fork);
		return ;
	}
	ft_printer("has taken a fork", philo);
	pthread_mutex_lock(philo->right_fork);
	if (is_alive(philo) == 0)
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		return ;
	}
	ft_printer("has taken a fork", philo);
}

void	philo_take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->right_fork);
		if (is_alive(philo) == 0)
		{
			pthread_mutex_unlock(philo->right_fork);
			return ;
		}
		ft_printer("has taken a fork", philo);
		pthread_mutex_lock(philo->left_fork);
		if (is_alive(philo) == 0)
		{
			pthread_mutex_unlock(philo->left_fork);
			pthread_mutex_unlock(philo->right_fork);
			return ;
		}
		ft_printer("has taken a fork", philo);
	}
	else
		philo_take_forks2(philo);
}

void	philo_eat(t_philo *philo)
{
	if (is_alive(philo) == 0)
		return ;
	ft_printer("is eating", philo);
	if (custom_usleep(philo->data->time_to_eat, philo))
	{
		if (philo->data->num_of_times_philo_must_eat != -1)
		{
			pthread_mutex_lock(&philo->data->locker);
			philo->dishes_eaten++;
			pthread_mutex_unlock(&philo->data->locker);
		}
		philo->last_meal = get_time();
	}
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	philo_sleep(t_philo *philo)
{
	if (is_alive(philo) == 0)
		return ;
	ft_printer("is sleeping", philo);
	custom_usleep(philo->data->time_to_sleep, philo);
}

void	routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->data->num_of_philo == 1)
	{
		printf("0 1 has taken a fork\n");
		custom_usleep(philo->data->time_to_die + 1, philo);
		return ;
	}
	while (is_alive(philo))
	{
		philo_take_forks(philo);
		philo_eat(philo);
		philo_sleep(philo);
		if (is_alive(philo) == 0)
			return ;
		ft_printer("is thinking", philo);
	}
}
