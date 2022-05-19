/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilahyani <ilahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 10:35:53 by ilahyani          #+#    #+#             */
/*   Updated: 2022/05/19 21:32:05 by ilahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char** argv)
{
	t_philo	*philo = NULL;

	if (error_check(argc, argv))
		if (printf("Invalid Arguments, Please Try Again!\n"))
			return (0);
	philo = get_args(argv);
	pthread_mutex_init(&philo->args.main, NULL);
	pthread_mutex_lock(&philo->args.main);
	if (philo_create(philo))
		if(printf("Thread creation failed\n"))
			return (0);
	pthread_mutex_lock(&philo->args.main);	//unlock when someone's dead
	pthread_mutex_unlock(&philo->args.main);
	pthread_mutex_destroy(&philo->args.main);
	return (0);
}
