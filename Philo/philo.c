/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilahyani <ilahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 10:35:53 by ilahyani          #+#    #+#             */
/*   Updated: 2022/05/22 17:54:01 by ilahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char** argv)
{
	t_philo			*philo = NULL;
	pthread_t		death_check;

	if (error_check(argc, argv))
		if (printf("Invalid Arguments, Please Try Again!\n"))
			return (0);
	philo = get_args(argv);
	pthread_mutex_init(&philo->args.main, NULL);
	pthread_mutex_init(&philo->args.print, NULL);
	pthread_mutex_lock(&philo->args.main);
	if (philo_create(philo))
		if(printf("Thread creation failed\n"))
			return (0);
	if ((pthread_create(&death_check, NULL, &is_dead, philo)) != 0)
		if(printf("unexpected error occurred \n"))
			return (0);
	if ((pthread_detach(death_check)) != 0)
		if(printf("unexpected error occurred \n"))
			return (0);
	pthread_mutex_lock(&philo->args.main);
	pthread_mutex_unlock(&philo->args.main);
	pthread_mutex_unlock(&philo->args.death);
	pthread_mutex_destroy(&philo->args.main);
	pthread_mutex_destroy(&philo->args.print);
	return (0);
}
