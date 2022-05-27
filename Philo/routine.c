/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilahyani <ilahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:39:34 by ilahyani          #+#    #+#             */
/*   Updated: 2022/05/27 16:25:44 by ilahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->args->fork[philo->right_fork]);
	thread_print(philo, "picked up the right fork");
	if (philo->left_fork != -1)
	{
		pthread_mutex_lock(&philo->args->fork[philo->left_fork]);
		thread_print(philo, "picked up the left fork");
		thread_print(philo, "is eating...");
		ft_usleep(philo->args->t_eat * 1000);
		philo->last_meal = ft_time();
		(philo->meals)++;
		pthread_mutex_unlock(&philo->args->fork[philo->left_fork]);
		pthread_mutex_unlock(&philo->args->fork[philo->right_fork]);
		return (1);
	}
	return (0);
}

void	*routine(void *philo)
{
	t_philo	*p;

	p = (t_philo *)philo;
	while (1)
	{
		if (p->id % 2 == 0)
			ft_usleep(2000);
		if (eat(p))
		{
			thread_print(philo, "is sleeping...");
			ft_usleep(p->args->t_sleep * 1000);
			thread_print(philo, "is thinking...");
		}
	}
	return (NULL);
}
