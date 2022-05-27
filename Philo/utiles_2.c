/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilahyani <ilahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:45:29 by ilahyani          #+#    #+#             */
/*   Updated: 2022/05/27 17:11:21 by ilahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}

void	ft_usleep(useconds_t time)
{
	long	t_time;

	t_time = ft_time();
	while (ft_time() - t_time < time / 1000)
		usleep(300);
}

void	thread_print(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->args->print);
	printf("%ld philo %d %s\n", ft_time() - philo->start, philo->id + 1, str);
	pthread_mutex_unlock(&philo->args->print);
}

void	clean_up(t_philo *philo)
{
	int	i;

	pthread_mutex_unlock(&philo->args->main);
	pthread_mutex_unlock(&philo->args->death);
	pthread_mutex_destroy(&philo->args->death);
	pthread_mutex_destroy(&philo->args->main);
	pthread_mutex_destroy(&philo->args->print);
	i = -1;
	while (++i < philo->args->num)
		pthread_mutex_destroy(&philo->args->fork[i]);
	free(philo->args->fork);
	free(philo->args);
}
