#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

struct s_data;

typedef struct s_philo
{
	int				id;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	unsigned long	last_meal;
	int				dishes_eaten;
	unsigned long	init_time;
	pthread_t		thread_id;
	struct s_data	*data;
}					t_philo;

typedef struct s_data
{
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_times_philo_must_eat;
	pthread_mutex_t	*forks;
	pthread_mutex_t	printer;
	pthread_mutex_t	locker;
	bool			someone_died;
	t_philo			*philos;
}					t_data;

int					ft_atoi(char *str);
unsigned long		get_time(void);
int					custom_usleep(int time, t_philo *philo);
void				ft_printer(char *str, t_philo *philo);
int					is_alive(t_philo *philo);
bool				is_everyone_full(t_data *args);
void				routine(void *arg);

#endif