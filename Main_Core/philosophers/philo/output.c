#include "./philo.h"

void	philo_print(t_person *philo, char *str, int flag)
{
	unsigned long long	time;

	if (!get_go(philo->global))
		return ;
	pthread_mutex_lock(&philo->global->printf);
	time = current_time();
	printf("%05lld %lld %s\n", time - philo->global->start_time, philo->id,
		str);
	if (flag)
		pthread_mutex_unlock(&philo->global->printf);
	else
		philo->global->locked = 1;
}

int	get_go(t_global *global)
{
	int	idx;

	idx = 1;
	pthread_mutex_lock(&global->eating);
	if (global->go == 0)
		idx = 0;
	pthread_mutex_unlock(&global->eating);
	return (idx);
}

void	eating(t_person *philo)
{
	pthread_mutex_lock(&philo->global->forks[philo->right_hand]);
	philo_print(philo, "has taken a fork", 1);
	pthread_mutex_lock(&philo->global->forks[philo->left_hand]);
	philo_print(philo, "has taken a fork", 1);
	pthread_mutex_lock(&philo->global->checker);
	philo_print(philo, "is eating", 1);
	philo->time_last_food = current_time();
	pthread_mutex_unlock(&philo->global->checker);
	ft_custom_sleep(philo->global->time_to_eat, philo->global);
	pthread_mutex_lock(&philo->global->checker);
	philo->counter_fed++;
	pthread_mutex_unlock(&philo->global->checker);
}

void	helper_die_check(t_global *global)
{
	long long	idx;
	long long	time;

	idx = 0;
	while (idx < global->num_philo && get_go(global))
	{
		pthread_mutex_lock(&global->checker);
		time = current_time();
		if ((time - global->person[idx].time_last_food) >= global->time_to_die)
		{
			philo_print(&global->person[idx], "died", 0);
			pthread_mutex_lock(&global->eating);
			global->go = 0;
			pthread_mutex_unlock(&global->eating);
		}
		idx++;
		pthread_mutex_unlock(&global->checker);
	}
}

int	hepler_start_philo(t_global *global)
{
	long long	idx;

	global->start_time = current_time();
	idx = -1;
	while (++idx < global->num_philo)
	{
		if (idx % 2 == 0)
		{
			global->person[idx].left_hand = idx;
			global->person[idx].right_hand = (idx + 1) % global->num_philo;
		}
		else
		{
			global->person[idx].left_hand = (idx + 1) % global->num_philo;
			global->person[idx].right_hand = idx;
		}
		global->person[idx].id = idx + 1;
		global->person[idx].global = global;
		global->person[idx].counter_fed = 0;
		global->person[idx].time_last_food = current_time();
		if (pthread_create(&global->person[idx].th, NULL, &start_life,
				&global->person[idx]))
			return (1);
	}
	return (0);
}
