#ifndef PHILO_H
#define PHILO_H

#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <stdbool.h>

struct s_data;

typedef struct s_philo
{
    int id;
    unsigned long time_to_die;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;
    unsigned long last_meal;
    unsigned long time_to_eat;
    unsigned long time_to_sleep;
    unsigned long init_time;
    pthread_t thread_id;
    struct s_data *data;
} t_philo;

typedef struct s_data
{
    int num_of_philo;                     //* Number of forks as well.
    int time_to_die;                      //* If a philosopher didn’t start eating time_to_die milliseconds since the beginning of their last meal or the beginning of the simulation, they die.
    int time_to_eat;                      //* The time it takes for a philosopher to eat. During that time, they will need to hold two forks.
    int time_to_sleep;                    //* The time a philosopher will spend sleeping.
    int num_of_times_each_philo_must_eat; //* If all philosophers have eaten at least number_of_times_each_philosopher_must_eat times, the simulation stops. If not specified, the simulation stops when a philosopher dies.
    pthread_mutex_t *forks;
    pthread_mutex_t printer;
    pthread_mutex_t locker;
    bool someone_died;
    t_philo *philos;
} t_data;

int ft_atoi(char *str);
unsigned long get_time(void);
void custom_usleep(int time);
void ft_printer(char *str, t_philo *philo);
void ddddestroyer(t_data *args);

#endif