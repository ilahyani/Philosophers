/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilahyani <ilahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:44:32 by ilahyani          #+#    #+#             */
/*   Updated: 2022/05/27 17:24:59 by ilahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_create(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->args->num)
	{
		philo[i].start = ft_time();
		if ((pthread_create(&philo[i].ph, NULL, &routine, &philo[i])) != 0)
			return (1);
	}
	i = -1;
	while (++i < philo->args->num)
		if ((pthread_detach(philo[i].ph) != 0))
			return (1);
	return (0);
}
