/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilahyani <ilahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 10:36:52 by ilahyani          #+#    #+#             */
/*   Updated: 2022/05/17 19:09:13 by ilahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#   define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

typedef	struct philo
{
	pthread_t	ph;
	int			id;
	int			left_fork;
	int			right_fork;
}	t_philo;

typedef struct args
{
	int				num;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				n_eat;
	t_philo			*philo;
	pthread_mutex_t	main;
	pthread_mutex_t	print;
	pthread_mutex_t	*forks;
}	t_args;

pthread_mutex_t	*get_args(t_args *args, char **av);
int				is_int(char* c);
int				error_check(int argc, char** argv);
int				ft_atoi(char *str);
int				philo_create(t_args *args);
void			*routine(void *args);
int				ft_perror(char *str);
void			eat(t_args *args);
void			thread_print (t_args *args, char *str);

#endif