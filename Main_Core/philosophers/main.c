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

int is_alive(t_philo philo)
{
    unsigned long time = get_time();
    if (philo.last_meal != 0 && philo.last_meal - time > (unsigned long)philo.time_to_die)
        return 0;

    return 1;
}

void custom_usleep(int time)
{
    unsigned long start;

    start = get_time();
    while (get_time() - start < (unsigned long)time)
        usleep(1);
}

void philo_take_forks(t_philo philo)
{
    pthread_mutex_lock(philo.left_fork);
    pthread_mutex_lock(philo.locker);
    printf("%ld %d has taken a fork\n", get_time() - (unsigned long)philo.init_time, philo.id);
    pthread_mutex_unlock(philo.locker);
    pthread_mutex_lock(philo.right_fork);
    pthread_mutex_lock(philo.locker);
    printf("%ld %d has taken a fork\n", get_time() - (unsigned long)philo.init_time, philo.id);
    pthread_mutex_unlock(philo.locker);
    // usleep(100);
}

void philo_eat(t_philo philo)
{
    printf("%ld %d is eating\n", get_time() - (unsigned long)philo.init_time, philo.id);
    // custom_usleep(philo.time_to_eat);
    philo.last_meal = get_time();
    pthread_mutex_unlock(philo.left_fork);
    pthread_mutex_unlock(philo.right_fork);
}

void philo_sleep(t_philo philo)
{
    pthread_mutex_lock(philo.locker);
    printf("%ld %d is sleeping\n", get_time() - (unsigned long)philo.init_time, philo.id);
    pthread_mutex_unlock(philo.locker);
    custom_usleep(philo.time_to_sleep);
}

void routine(void *arg)
{
    t_philo philo;
    philo = *(t_philo *)arg;
    // printf("Thread: %d\n", getpid());
    printf("Thread: %ld\n", pthread_self());
    // while (is_alive(philo))
    while (1)
    {
        philo_take_forks(philo);
        philo_eat(philo);
        philo_sleep(philo);
        // printf("%ld %d is sleeping\n", get_time() - (unsigned long)philo.init_time, philo.id);
    }
}

void init_philosophers(t_data args)
{
    int idx = -1;
    size_t time = get_time();
    args.philos = malloc(sizeof(t_philo) * args.num_of_philo);
    args.forks = malloc(args.num_of_philo * sizeof(pthread_mutex_t));
    while (++idx < args.num_of_philo)
        pthread_mutex_init(&args.forks[idx], NULL);
    idx = -1;
    while (++idx < args.num_of_philo)
    {
        args.philos[idx].id = idx + 1;
        args.philos[idx].last_meal = 0;
        args.philos[idx].init_time = time;
        args.philos[idx].time_to_die = args.time_to_die;
        args.philos[idx].time_to_eat = args.time_to_eat;
        args.philos[idx].time_to_sleep = args.time_to_sleep;
        args.philos[idx].locker = &args.locker;
        args.philos[idx].right_fork = &args.forks[idx]; // and for one philo??
        if (idx == args.num_of_philo - 1)
            args.philos[idx].left_fork = &args.forks[0];
        else
            args.philos[idx].left_fork = &args.forks[idx + 1];
        printf("Iteration...\n");
        pthread_create(&args.philos[idx].thread_id, NULL, (void *)routine, &args.philos[idx]);
    }
}
// if one philo...
//
// else

int main(int argc, char **argv)
{
    t_data args;

    data_validator(argc, argv, &args);
    args.num_of_philo = ft_atoi(argv[1]);
    args.time_to_die = ft_atoi(argv[2]);
    args.time_to_eat = ft_atoi(argv[3]);
    args.time_to_sleep = ft_atoi(argv[4]);
    pthread_mutex_init(&args.locker, NULL);
    // pthread_mutex_init(&table.forks[i], NULL);
    if (argv[5])
        args.num_of_times_each_philo_must_eat = ft_atoi(argv[5]);
    else
        args.num_of_times_each_philo_must_eat = -1;
    init_philosophers(args);
    return 1;
}

// int num_of_philo;                     //* number of forks as well
// int time_to_die;                      //* If a philosopher didn’t start eating time_to_die milliseconds since the beginning of their last meal or the beginning of the simulation, they die.
// int time_to_eat;                      //* The time it takes for a philosopher to eat. During that time, they will need to hold two forks.
// int time_to_sleep;                    //* The time a philosopher will spend sleeping.
// int num_of_times_each_philo_must_eat; //* If all philosophers have eaten at least number_of_times_each_philosopher_must_eat times, the simulation stops. If not specified, the simulation stops when a philosopher dies.
