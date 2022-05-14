/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilahyani <ilahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 10:36:52 by ilahyani          #+#    #+#             */
/*   Updated: 2022/05/14 19:32:25 by ilahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#   define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct args
{
	int	num;
	int	t_die;
	int	t_eat;
	int	t_sleep;
	int	n_eat;
	pthread_mutex_t	forks;
}	t_args;

int		error_check(int argc, char** argv);
int		is_int(char* c);
int		ft_atoi(char *str);
int		philo_create(int num);
void	*routine();
void	ft_perror(char *str);

#endif