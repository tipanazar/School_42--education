#include "philo.h"

int ft_atoi(char *str)
{
    int i;
    int res;
    int sign;

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

unsigned long get_time(void)
{
    unsigned long ms;
    struct timeval tv;

    gettimeofday(&tv, NULL);
    ms = (tv.tv_sec * 1000UL) + (tv.tv_usec / 1000UL);
    return (ms);
}

void custom_usleep(int time)
{
    unsigned long start;
    start = get_time();
    while ((get_time() - start) < (unsigned long)time)
        usleep(time / 10);
}

void ft_printer(char *str, t_philo *philo)
{
    pthread_mutex_lock(&philo->data->printer);
    printf("%ld %d %s\n", get_time() - (unsigned long)philo->init_time, philo->id, str);
    pthread_mutex_unlock(&philo->data->printer);
}

void ddddestroyer(t_data *args)
{
    int idx = -1;
    while (++idx < args->num_of_philo)
        pthread_join(args->philos[idx].thread_id, NULL);
    idx = -1;
    while (++idx < args->num_of_philo)
        pthread_mutex_destroy(&args->forks[idx]);

    pthread_mutex_destroy(&args->printer);
    pthread_mutex_destroy(&args->locker);
    // idx = -1;
    // while (++idx < args->num_of_philo)
    // {
    //     free(args->philos[idx]);
    // }
    free(args->philos);
    free(args->forks);
}