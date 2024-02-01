#include "philo.h"

int	ft_atoi(char *str)
{
	int	i;
	int	res;
	int	sign;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += str[i] - 48;
		i++;
	}
	return (res * sign);
}

unsigned long	get_time(void)
{
	unsigned long	ms;
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	ms = (tv.tv_sec * 1000UL) + (tv.tv_usec / 1000UL);
	return (ms);
}

// void	custom_usleep(int time)
// {
// 	unsigned long	start;

// 	start = get_time();
// 	while ((get_time() - start) < (unsigned long)time)
// 		usleep(time / 10);
// }

int	custom_usleep(int time, t_philo *philo)
{
	unsigned long	start;

	start = get_time();
	while ((get_time() - start) < (unsigned long)time)
	{
		if (is_alive(philo) == 0)
			return 0;
		usleep(1);
	}
    return 1;
}

void	ft_printer(char *str, t_philo *philo)
{
	pthread_mutex_lock(&philo->data->printer);
	printf("%ld %d %s\n", get_time() - (unsigned long)philo->init_time,
		philo->id, str);
	pthread_mutex_unlock(&philo->data->printer);
}

int	is_alive(t_philo *philo)
{
	unsigned long	time;

	pthread_mutex_lock(&philo->data->locker);
	if (philo->data->someone_died)
	{
		pthread_mutex_unlock(&philo->data->locker);
		return (0);
	}
	time = get_time();
	// if (time
	// 	- philo->last_meal >= (unsigned long)philo->time_to_die)
	if (philo->last_meal != 0 && time
		- philo->last_meal >= (unsigned long)philo->time_to_die)
	{
		philo->data->someone_died = true;
		ft_printer("died", philo);
		pthread_mutex_unlock(&philo->data->locker);
		return (0);
	}
	pthread_mutex_unlock(&philo->data->locker);
	return (1);
}
