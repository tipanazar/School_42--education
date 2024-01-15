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

// void *routine(void *arg)
// {
//     t_data *philo;

//     philo = (t_data *)arg;
//     while (1)
//     {
//         // think
//         // take forks
//         // eat
//         // put forks
//         // sleep
//     }
// }

void init_philosophers()
{
    
}

int main(int argc, char **argv)
{
    t_data args;

    data_validator(argc, argv, &args);
    args.num_of_philo = argv[1];
    args.time_to_die = argv[2];
    args.time_to_eat = argv[3];
    args.time_to_sleep = argv[4];
    if (argv[5])
        args.num_of_times_each_philo_must_eat = argv[5];
    else 
        args.num_of_times_each_philo_must_eat = -1;    
}

// int num_of_philo;                     //* number of forks as well
// int time_to_die;                      //* If a philosopher didn’t start eating time_to_die milliseconds since the beginning of their last meal or the beginning of the simulation, they die.
// int time_to_eat;                      //* The time it takes for a philosopher to eat. During that time, they will need to hold two forks.
// int time_to_sleep;                    //* The time a philosopher will spend sleeping.
// int num_of_times_each_philo_must_eat; //* If all philosophers have eaten at least number_of_times_each_philosopher_must_eat times, the simulation stops. If not specified, the simulation stops when a philosopher dies.
