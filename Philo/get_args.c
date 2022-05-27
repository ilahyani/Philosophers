/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilahyani <ilahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:42:25 by ilahyani          #+#    #+#             */
/*   Updated: 2022/05/27 16:29:10 by ilahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_args	*get_data(char **av)
{
	t_args	*args;

	args = (t_args *)malloc(sizeof(t_args));
	if (!args)
		return (NULL);
	args->num = ft_atoi(av[1]);
	args->t_die = ft_atoi(av[2]);
	args->t_eat = ft_atoi(av[3]);
	args->t_sleep = ft_atoi(av[4]);
	if (av[5])
		args->num_of_meals = ft_atoi(av[5]);
	args->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * args->num);
	if (!args->fork)
		return (NULL);
	return (args);
}

t_philo	*get_args(char **av)
{
	t_philo	*philo;
	t_args	*args;
	int		i;

	args = get_data(av);
	philo = (t_philo *)malloc(sizeof(t_philo) * ft_atoi(av[1]));
	if (!philo)
		return (NULL);
	i = -1;
	while (++i < args->num)
		pthread_mutex_init(&args->fork[i], NULL);
	i = -1;
	while (++i < args->num)
	{
		philo[i].id = i;
		philo[i].right_fork = i;
		philo[i].left_fork = (i + 1) % args->num;
		if (args->num < 2)
			philo[i].left_fork = -1;
		philo[i].last_meal = ft_time();
		philo[i].meals = 0;
		philo[i].args = args;
	}
	return (philo);
}
