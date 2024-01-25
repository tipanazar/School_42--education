#include "./philo.h"

void data_validator(int argc, char **argv, t_data *args)
{
    if (argc < 5 || argc > 6)
    {
        printf("Error: Wrong number of arguments\n");
        exit(1);
    }
    args->num_of_philo = ft_atoi(argv[1]);
    args->time_to_die = ft_atoi(argv[2]);
    args->time_to_eat = ft_atoi(argv[3]);
    args->time_to_sleep = ft_atoi(argv[4]);
    if (argv[5])
        args->num_of_times_each_philo_must_eat = ft_atoi(argv[5]);
    else
        args->num_of_times_each_philo_must_eat = -1;
    if (args->num_of_philo < 1 || args->num_of_philo > 200 || args->time_to_die < 1 || args->time_to_eat < 1 || args->time_to_sleep < 1 || (args->num_of_times_each_philo_must_eat < 1 && args->num_of_times_each_philo_must_eat != -1))
    {
        printf("Error: Arguments are not valid!\n");
        exit(1);
    }
}

int is_alive(t_philo *philo)
{
    unsigned long time = get_time();
    if (philo->last_meal != 0 && time - philo->last_meal >= (unsigned long)philo->time_to_die)
    {
        ft_printer("died", philo);
        return 0;
    }

    return 1;
}

// void philo_take_forks(t_philo *philo)
// {
//     pthread_mutex_lock(&philo->left_fork);
//     ft_printer("has taken a fork", philo);
//     pthread_mutex_lock(&philo->right_fork);
//     ft_printer("has taken a fork", philo);
// }

void philo_take_forks(t_philo *philo)
{
    pthread_mutex_lock(&philo->left_fork);
    ft_printer("has taken a left fork", philo);
    pthread_mutex_lock(&philo->right_fork);
    ft_printer("has taken a right fork", philo);
}

void philo_eat(t_philo *philo)
{
    ft_printer("is eating", philo);
    custom_usleep(philo->time_to_eat);
    philo->last_meal = get_time();
    pthread_mutex_unlock(&philo->left_fork);
    pthread_mutex_unlock(&philo->right_fork);
}

void philo_sleep(t_philo *philo)
{
    ft_printer("is sleeping", philo);
    custom_usleep(philo->time_to_sleep);
}

void routine(void *arg)
{
    t_philo *philo;
    philo = (t_philo *)arg;
    if (philo->id % 2 == 0)
        usleep(50); //* ??
    while (is_alive(philo))
    {
        philo_take_forks(philo);
        philo_eat(philo);
        philo_sleep(philo);
    }
}

void init_philosophers(t_data *args)
{
    int idx = -1;
    size_t time = get_time();
    args->philos = malloc(sizeof(t_philo) * args->num_of_philo);
    // args->forks = malloc(args->num_of_philo * sizeof(pthread_mutex_t));
    while (++idx < args->num_of_philo)
    {
        args->philos[idx].id = idx + 1;
        args->philos[idx].last_meal = 0;
        args->philos[idx].init_time = time;
        args->philos[idx].time_to_die = args->time_to_die;
        args->philos[idx].time_to_eat = args->time_to_eat;
        args->philos[idx].time_to_sleep = args->time_to_sleep;
        args->philos[idx].data = args;
        args->philos[idx].right_fork = args->forks[idx]; // and for one philo??
        if (idx + 1 == args->num_of_philo)
            args->philos[idx].left_fork = args->forks[0];
        else
            args->philos[idx].left_fork = args->forks[idx + 1];
        pthread_create(&args->philos[idx].thread_id, NULL, (void *)routine, &args->philos[idx]);
    }
}

int main(int argc, char **argv)
{
    t_data args;
    int idx = -1;

    data_validator(argc, argv, &args);
    args.forks = malloc((args.num_of_philo + 1) * sizeof(pthread_mutex_t));
    pthread_mutex_init(&args.printer, NULL);
    while (++idx < args.num_of_philo)
        pthread_mutex_init(&args.forks[idx], NULL);

    init_philosophers(&args);
    destroyer(args);
    return 0;
}

// int main(void)
// {
//     printf("Time: %ld\n", get_time());
//     custom_usleep(100);
//     printf("Time: %ld\n", get_time());
//     return 0;
// }

// printf("Is locked: %d\n", pthread_mutex_trylock(&philo->data->printer));
// pthread_mutex_unlock(&philo->left_fork);

// int num_of_philo;                     //* number of forks as well
// int time_to_die;                      //* If a philosopher didn’t start eating time_to_die milliseconds since the beginning of their last meal or the beginning of the simulation, they die.
// int time_to_eat;                      //* The time it takes for a philosopher to eat. During that time, they will need to hold two forks.
// int time_to_sleep;                    //* The time a philosopher will spend sleeping.
// int num_of_times_each_philo_must_eat; //* If all philosophers have eaten at least number_of_times_each_philosopher_must_eat times, the simulation stops. If not specified, the simulation stops when a philosopher dies.
