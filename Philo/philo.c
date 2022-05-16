/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilahyani <ilahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 10:35:53 by ilahyani          #+#    #+#             */
/*   Updated: 2022/05/16 13:01:56 by ilahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char** argv)
{
	//pthread_mutex_t	*forks;
	t_args	args;

	if (error_check(argc, argv))
		if (ft_perror("Invalid Arguments, Please Try Again!\n"))
			return (0);
	args.forks = get_args(&args, argv);
	// pthread_mutex_init(&args.main, NULL);
	// pthread_mutex_lock(&args.main);
	if (philo_create(&args))
		if(ft_perror("Thread creation failed\n"))
			return (0);
	// pthread_mutex_lock(&args.main);//unlock when someone's dead
	// pthread_mutex_unlock(&args.main);
	// pthread_mutex_destroy(&args.main);
	return (0);
}
