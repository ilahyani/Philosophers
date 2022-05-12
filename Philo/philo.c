/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilahyani <ilahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 10:35:53 by ilahyani          #+#    #+#             */
/*   Updated: 2022/05/12 14:29:59 by ilahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_mutex_t	mutex;

void	*routine();

int	main(int argc, char** argv)
{
	pthread_mutex_init(&mutex, NULL);
	if (error_check(argc, argv))
		ft_perror("Invalid Arguments, Please Try Again!\n");
	philo_create(ft_atoi(argv[1])); 	//Handle Errors
	pthread_mutex_destroy(&mutex);
	return (0);
}

void	*routine()
{
	//pthread_mutex_lock(&mutex);
	printf("philo born ._.\n");
	sleep(2);
	printf("philo dead x_x\n");
	//pthread_mutex_unlock(&mutex);
	return (NULL);
}
