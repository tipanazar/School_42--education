#ifndef PHILO_H
#define PHILO_H
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>

typedef struct global t_global;

typedef struct person
{
	long long left_hand;
	long long right_hand;
	long long id;
	long long time_last_food;
	long long counter_fed;
	pthread_t th;
	t_global *global;
} t_person;

typedef struct global
{
	long long num_philo;
	long long num_fed;
	int go;
	int locked;
	long long time_to_die;
	long long time_to_eat;
	long long time_to_sleep;
	long long num_times_feed;
	unsigned long long start_time;
	pthread_mutex_t printf;
	pthread_mutex_t checker;
	pthread_mutex_t eating;
	pthread_mutex_t *forks;
	t_person *person;
} t_global;

int ft_check_args(char **argv, t_global *philos);
int ft_isnums(char **str);
void *start_life(void *arg);
int ft_start_philo(t_global *global);
long long ft_atoi(const char *str);
long long current_time(void);
void ft_free_philo(t_global *global);
void ft_custom_sleep(long long
						 time,
					 t_global *global);
void ft_die_check(t_global *global);
void philo_print(t_person *philo, char *str, int flag);
int get_go(t_global *global);
void eating(t_person *philo);
void helper_die_check(t_global *global);
int hepler_start_philo(t_global *global);

#endif