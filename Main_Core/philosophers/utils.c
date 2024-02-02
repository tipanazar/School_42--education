#include "philo.h"

int	ft_atoi(char *str)
{
	int	idx;
	int	res;
	int	sign;

	idx = 0;
	res = 0;
	sign = 1;
	while (str[idx] == 32 || (str[idx] >= 9 && str[idx] <= 13))
		idx++;
	while (str[idx] == '-' || str[idx] == '+')
	{
		if (str[idx] == '-')
			sign *= -1;
		idx++;
	}
	while (str[idx] >= '0' && str[idx] <= '9')
	{
		res *= 10;
		res += str[idx] - 48;
		idx++;
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

int	custom_usleep(int time, t_philo *philo)
{
	unsigned long	start;

	start = get_time();
	while ((get_time() - start) < (unsigned long)time)
	{
		if (is_alive(philo) == 0)
			return (0);
		usleep(1);
	}
	return (1);
}

void	ft_printer(char *str, t_philo *philo)
{
	pthread_mutex_lock(&philo->data->printer);
	printf("%ld %d %s\n", get_time() - (unsigned long)philo->init_time,
		philo->id, str);
	pthread_mutex_unlock(&philo->data->printer);
}

bool	is_everyone_full(t_data *args)
{
	int	idx;

	idx = -1;
	while (++idx < args->num_of_philo)
		if (args->philos[idx].dishes_eaten < args->num_of_times_philo_must_eat)
			return (false);
	return (true);
}
