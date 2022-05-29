/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilahyani <ilahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:40:39 by ilahyani          #+#    #+#             */
/*   Updated: 2022/05/29 19:40:26 by ilahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_meals(t_philo *p)
{
	int	i;

	i = -1;
	while (++i < p->args->num)
		if ((p + i)->meals < p->args->num_of_meals)
			break ;
	if (i == p->args->num)
	{
		pthread_mutex_lock(&p->args->print);
		printf("All philosophers are served.\n");
		pthread_mutex_unlock(&p->args->main);
		return (1);
	}
	return (0);
}

void	*kill_thread(void *philo)
{
	t_philo	*p;

	p = (t_philo *)philo;
	while (1)
	{
		if (ft_time() - p->last_meal > p->args->t_die)
		{
			pthread_mutex_lock(&p->args->death);
			thread_print(philo, "died");
			pthread_mutex_unlock(&p->args->main);
			return (NULL);
		}
		if (p->args->num_of_meals)
			if (check_meals(p))
				return (NULL);
		usleep(50);
	}
}
