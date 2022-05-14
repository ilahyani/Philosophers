/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilahyani <ilahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 10:35:53 by ilahyani          #+#    #+#             */
/*   Updated: 2022/05/14 19:36:49 by ilahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine();

void	get_args(t_args *args, char **av);

int	main(int argc, char** argv)
{
	pthread_mutex_t	forks;
	t_args	args;

	pthread_mutex_init(&forks, NULL);
	if (error_check(argc, argv))
		ft_perror("Invalid Arguments, Please Try Again!\n");
	get_args(&args, argv);
	if (philo_create(args.num))
		ft_perror("Thread creation failed\n");
	pthread_mutex_destroy(&forks);
	return (0);
}

void	*routine()
{
	//pthread_mutex_lock(&forks);
	printf("philo born ._.\n");
	sleep(1);
	printf("philo dead x_x\n");
	//pthread_mutex_unlock(&forks);
	return (NULL);
}

void	get_args(t_args *args, char **av)	//return forks[num]???
{
	args->num = ft_atoi(av[1]);
	args->t_die = ft_atoi(av[2]);
	args->t_eat = ft_atoi(av[3]);
	args->t_sleep = ft_atoi(av[4]);
	if (av[5])
		args->n_eat = ft_atoi(av[5]);
}
