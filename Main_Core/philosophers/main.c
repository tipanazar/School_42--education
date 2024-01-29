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
    unsigned long time;
    pthread_mutex_lock(&philo->data->locker);
    if (philo->data->someone_died)
    {
        pthread_mutex_unlock(&philo->data->locker);
        return 0;
    }
    pthread_mutex_unlock(&philo->data->locker);

    time = get_time();
    if (philo->last_meal != 0 && time - philo->last_meal >= (unsigned long)philo->time_to_die)
    {
        pthread_mutex_lock(&philo->data->locker);
        philo->data->someone_died = true;
        pthread_mutex_unlock(&philo->data->locker);
        ft_printer("died", philo);
        return 0;
    }

    return 1;
}

void philo_take_forks(t_philo *philo)
{
    if (philo->id % 2 == 0)
    {
        pthread_mutex_lock(philo->right_fork);
        if (is_alive(philo) == 0)
        {
            pthread_mutex_unlock(philo->right_fork);
            return;
        }
        ft_printer("has taken a fork", philo);
        pthread_mutex_lock(philo->left_fork);
        if (is_alive(philo) == 0)
        {
            pthread_mutex_unlock(philo->left_fork);
            pthread_mutex_unlock(philo->right_fork);
            return;
        }
        ft_printer("has taken a fork", philo);
    }
    else
    {
        pthread_mutex_lock(philo->left_fork);
        if (is_alive(philo) == 0)
        {
            pthread_mutex_unlock(philo->left_fork);
            return;
        }
        ft_printer("has taken a fork", philo);
        pthread_mutex_lock(philo->right_fork);
        if (is_alive(philo) == 0)
        {
            pthread_mutex_unlock(philo->left_fork);
            pthread_mutex_unlock(philo->right_fork);
            return;
        }
        ft_printer("has taken a fork", philo);
    }
}

void philo_eat(t_philo *philo)
{
    if (is_alive(philo) == 0)
        return;
    ft_printer("is eating", philo);
    custom_usleep(philo->time_to_eat);
    if (is_alive(philo))
        philo->last_meal = get_time();
    pthread_mutex_unlock(philo->left_fork);
    pthread_mutex_unlock(philo->right_fork);
}

void philo_sleep(t_philo *philo)
{
    if (is_alive(philo) == 0)
        return;
    ft_printer("is sleeping", philo);
    custom_usleep(philo->time_to_sleep);
}

void routine(void *arg)
{
    t_philo *philo;
    philo = (t_philo *)arg;
    while (is_alive(philo))
    {
        philo_take_forks(philo);
        philo_eat(philo);
        philo_sleep(philo);
        if (is_alive(philo) == 0)
            return;
        ft_printer("is thinking", philo);
    }
}

void init_philosophers(t_data *args)
{
    int idx = -1;
    while (++idx < args->num_of_philo)
    {
        args->philos[idx].id = idx + 1;
        args->philos[idx].last_meal = 0;
        args->philos[idx].init_time = get_time();
        args->philos[idx].time_to_die = args->time_to_die;
        args->philos[idx].time_to_eat = args->time_to_eat;
        args->philos[idx].time_to_sleep = args->time_to_sleep;
        args->philos[idx].data = args;
        args->philos[idx].right_fork = &args->forks[idx]; // and for one philo??
        if (idx + 1 == args->num_of_philo)
            args->philos[idx].left_fork = &args->forks[0];
        else
            args->philos[idx].left_fork = &args->forks[idx + 1];
        pthread_create(&args->philos[idx].thread_id, NULL, (void *)routine, &args->philos[idx]);
    }
}

int main(int argc, char **argv)
{
    t_data args;
    int idx = -1;

    data_validator(argc, argv, &args);
    args.forks = malloc((args.num_of_philo) * sizeof(pthread_mutex_t));
    args.philos = malloc(sizeof(t_philo) * args.num_of_philo);
    args.someone_died = false;
    pthread_mutex_init(&args.printer, NULL);
    pthread_mutex_init(&args.locker, NULL);
    while (++idx < args.num_of_philo)
        pthread_mutex_init(&args.forks[idx], NULL);
    init_philosophers(&args);
    ddddestroyer(&args);
    return 0;
}

// struct s_test
// {
//     pthread_mutex_t mutex;
//     pthread_t thread_id;
// };

// void test_func(void *arg)
// {
//     struct s_test *test_struct;
//     test_struct = (struct s_test *)arg;
//     pthread_mutex_lock(&test_struct->mutex);
//     printf("Locked: %ld\n\n", get_time());
// }

// int main(void)
// {
//     struct s_test test_struct;
//     pthread_mutex_init(&test_struct.mutex, NULL);
//     pthread_create(&test_struct.thread_id, NULL, (void *)test_func, &test_struct);
//     custom_usleep(1000);

//     printf("Try to lock: %d\n", pthread_mutex_trylock(&test_struct.mutex));
//     printf("Time: %ld\n", get_time());
//     // pthread_mutex_unlock(&test_struct.mutex);
//     pthread_join(test_struct.thread_id, NULL);
//     pthread_mutex_destroy(&test_struct.mutex);
//     return 0;
// }

// printf("Is locked: %d\n", pthread_mutex_trylock(&philo->data->printer));
// pthread_mutex_unlock(&philo->left_fork);

// int num_of_philo;                     //* number of forks as well
// int time_to_die;                      //* If a philosopher didn’t start eating time_to_die milliseconds since the beginning of their last meal or the beginning of the simulation, they die.
// int time_to_eat;                      //* The time it takes for a philosopher to eat. During that time, they will need to hold two forks.
// int time_to_sleep;                    //* The time a philosopher will spend sleeping.
// int num_of_times_each_philo_must_eat; //* If all philosophers have eaten at least number_of_times_each_philosopher_must_eat times, the simulation stops. If not specified, the simulation stops when a philosopher dies.
