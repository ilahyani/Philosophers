/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilahyani <ilahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:44:32 by ilahyani          #+#    #+#             */
/*   Updated: 2022/05/29 19:36:51 by ilahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}

int	philo_create(t_philo *philo)
{
	int	i;

	long start_time = ft_time();
	i = -1;
	while (++i < philo->args->num)
	{
		philo[i].start = start_time;
		if ((pthread_create(&philo[i].ph, NULL, &routine, &philo[i])) != 0)
		 	return (1);
		if ((pthread_detach(philo[i].ph) != 0))
			return (1);
		ft_usleep(1);
	}
	return (0);
}
