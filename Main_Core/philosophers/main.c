#include "./philo.h"

void	data_validator(int argc, char **argv, t_data *args)
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
	if (args->num_of_philo < 1 || args->num_of_philo > 200
		|| args->time_to_die < 1 || args->time_to_eat < 1
		|| args->time_to_sleep < 1
		|| (args->num_of_times_each_philo_must_eat < 1
			&& args->num_of_times_each_philo_must_eat != -1))
	{
		printf("Error: Arguments are not valid!\n");
		exit(1);
	}
}

void	init_philosophers(t_data *args)
{
	int	idx;

	idx = -1;
	while (++idx < args->num_of_philo)
	{
		args->philos[idx].id = idx + 1;
		args->philos[idx].init_time = get_time();
		args->philos[idx].last_meal = 0;
		args->philos[idx].time_to_die = args->time_to_die;
		args->philos[idx].time_to_eat = args->time_to_eat;
		args->philos[idx].time_to_sleep = args->time_to_sleep;
		args->philos[idx].data = args;
		args->philos[idx].right_fork = &args->forks[idx]; // and for one philo??
		if (idx + 1 == args->num_of_philo)
			args->philos[idx].left_fork = &args->forks[0];
		else
			args->philos[idx].left_fork = &args->forks[idx + 1];
		pthread_create(&args->philos[idx].thread_id, NULL, (void *)routine,
			&args->philos[idx]);
	}
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

int	main(int argc, char **argv)
{
	t_data	args;
	int		idx;

	idx = -1;
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
	return (0);
}
