/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilahyani <ilahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 10:35:53 by ilahyani          #+#    #+#             */
/*   Updated: 2022/05/19 18:57:38 by ilahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char** argv)
{
	t_philo	*philo = NULL;

	if (error_check(argc, argv))
		if (ft_perror("Invalid Arguments, Please Try Again!\n"))
			return (0);
	philo = get_args(argv);
	pthread_mutex_init(&philo->args.main, NULL);
	pthread_mutex_lock(&philo->args.main);
	if (philo_create(philo))
		if(ft_perror("Thread creation failed\n"))
			return (0);
	pthread_mutex_lock(&philo->args.main);	//unlock when someone's dead
	pthread_mutex_unlock(&philo->args.main);
	pthread_mutex_destroy(&philo->args.main);
	return (0);
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->args.forks[philo->right_fork]);
	thread_print(philo, "picked up the right fork");
	pthread_mutex_lock(&philo->args.forks[philo->left_fork]);
	thread_print(philo, "picked up the left fork");
	thread_print(philo, "is eating");
	usleep(philo->args.t_eat * 1000);
	pthread_mutex_unlock(&philo->args.forks[philo->left_fork]);
	pthread_mutex_unlock(&philo->args.forks[philo->left_fork]);
}

void	thread_print (t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->args.print);
	printf("%d %d %s\n",ft_time(), philo->id + 1, str);
	pthread_mutex_unlock(&philo->args.print);
}

int	ft_time(void)
{
	struct timeval  tv;
	int	time;
	
	gettimeofday(&tv, NULL);
	time = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
	return (time);
}