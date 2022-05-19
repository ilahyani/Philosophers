/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilahyani <ilahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 10:36:52 by ilahyani          #+#    #+#             */
/*   Updated: 2022/05/19 18:57:25 by ilahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#   define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct args
{
	int				num;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				n_eat;
	pthread_mutex_t	main;
	pthread_mutex_t	print;
	pthread_mutex_t	*forks;
}	t_args;

typedef	struct philo
{
	pthread_t	ph;
	int			id;
	int			left_fork;
	int			right_fork;
	t_args		args;
}	t_philo;

t_philo	*get_args(char **av);
int				is_int(char* c);
int				error_check(int argc, char** argv);
int				ft_atoi(char *str);
int				philo_create(t_philo *philo);
void			*routine(void *philo);
int				ft_perror(char *str);
void			eat(t_philo *philo);
int				ft_time(void);
void			thread_print (t_philo *philo, char *str);

#endif