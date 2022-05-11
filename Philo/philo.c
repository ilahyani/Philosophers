/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilahyani <ilahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 10:35:53 by ilahyani          #+#    #+#             */
/*   Updated: 2022/05/11 10:01:58 by ilahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_mutex_t	mutex;

void	*routine()
{
	//pthread_mutex_lock(&mutex);
	printf("philo born ._.\n");
	sleep(2);
	printf("philo dead x_x\n");
	//pthread_mutex_unlock(&mutex);
	return NULL;
}

int	main(int argc, char** argv)
{
	pthread_mutex_init(&mutex, NULL);
	if (error_check(argc, argv))
		printf("Error\n");				//EXIT HERE
	philo_create(ft_atoi(argv[1])); 	//Handle Errors
	pthread_mutex_destroy(&mutex);
	return (0);
}
