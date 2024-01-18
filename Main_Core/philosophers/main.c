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

// while (1)
// {
//     // think
//     // take forks
//     // eat
//     // put forks
//     // sleep
// }

int is_alive(void)
{
    return 1;
}

void routine(void *arg)
{
    t_philo philo;
    int idx = -1;
    philo = *(t_philo *)arg;
    printf("Hello from thread %ld\n", philo.thread_id);
    while(is_alive()) {

    }
}

void init_philosophers(t_data args)
{
    int idx = -1;
    size_t time = get_time();
    args.philos = malloc(sizeof(t_philo) * args.num_of_philo);
    args.forks = malloc(args.num_of_philo * sizeof(pthread_mutex_t));
    while (++idx <= args.num_of_philo)
    {
        args.philos[idx].id = idx + 1;
        args.philos[idx].last_meal = 0;
        args.philos[idx].init_time = time;
        args.philos[idx].right_fork = &args.forks[idx];
        if (idx == args.num_of_philo - 1)
            args.philos[idx].left_fork = &args.forks[0];
        else
            args.philos[idx].left_fork = &args.forks[idx + 1];
        // if one philo...
        //
        // else
        pthread_create(&args.philos[idx].thread_id, NULL, (void *)routine, &args.philos[idx]);
    }
}

int main(int argc, char **argv)
{
    t_data args;

    data_validator(argc, argv, &args);
    args.num_of_philo = ft_atoi(argv[1]);
    args.time_to_die = ft_atoi(argv[2]);
    args.time_to_eat = ft_atoi(argv[3]);
    args.time_to_sleep = ft_atoi(argv[4]);
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
