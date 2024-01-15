#ifndef PHILO_H
#define PHILO_H

#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct s_data
{
    int num_of_philo;                     //* number of forks as well
    int time_to_die;                      //* If a philosopher didn’t start eating time_to_die milliseconds since the beginning of their last meal or the beginning of the simulation, they die.
    int time_to_eat;                      //* The time it takes for a philosopher to eat. During that time, they will need to hold two forks.
    int time_to_sleep;                    //* The time a philosopher will spend sleeping.
    int num_of_times_each_philo_must_eat; //* If all philosophers have eaten at least number_of_times_each_philosopher_must_eat times, the simulation stops. If not specified, the simulation stops when a philosopher dies.
} t_data;



// typedef struct s_philo
// {
// 	struct s_data	*data;
// 	pthread_t       t1;
// 	int             id;
// 	int             eat_cont;
// 	int             status;
// 	int             eating;
// 	uint64_t        time_to_die;
// 	pthread_mutex_t	lock;
// 	pthread_mutex_t	*r_fork;
// 	pthread_mutex_t	*l_fork;
// } t_philo;

// typedef struct s_data
// {
// 	pthread_t       *tid;
// 	int             philo_num;
// 	int             meals_nb;
// 	int             dead;
// 	int             finished;
// 	t_philo         *philos;
// 	u_int64_t       death_time;
// 	u_int64_t       eat_time;
// 	u_int64_t       sleep_time;
// 	u_int64_t       start_time;
// 	pthread_mutex_t *forks;
// 	pthread_mutex_t lock;
// 	pthread_mutex_t write;
// } t_data;


int ft_atoi(char *str);

#endif