/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilahyani <ilahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 10:36:52 by ilahyani          #+#    #+#             */
/*   Updated: 2022/05/27 17:24:43 by ilahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct args
{
	pthread_mutex_t	main;
	pthread_mutex_t	print;
	pthread_mutex_t	death;
	pthread_mutex_t	*fork;
	long			t_die;
	int				t_sleep;
	int				num_of_meals;
	int				t_eat;
	int				num;
}	t_args;

typedef struct philo
{
	pthread_t	ph;
	t_args		*args;
	long		start;
	long		last_meal;
	int			left_fork;
	int			right_fork;
	int			meals;
	int			id;
}	t_philo;

t_philo		*get_args(char **av);
t_args		*get_data(char **av);
int			is_int(char *c);
int			error_check(int argc, char **argv);
int			ft_atoi(char *str);
int			philo_create(t_philo *philo);
void		*routine(void *philo);
int			eat(t_philo *philo);
long		ft_time(void);
void		thread_print(t_philo *philo, char *str);
void		*kill_thread(void *philo);
int			check_meals(t_philo	*p);
void		clean_up(t_philo *philo);
void		ft_usleep(useconds_t time);

#endif