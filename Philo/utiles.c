/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilahyani <ilahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:45:29 by ilahyani          #+#    #+#             */
/*   Updated: 2022/05/28 16:41:41 by ilahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str)
{
	int	i;
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' '
		|| str[i] == '\t'
		|| str[i] == '\n'
		|| str[i] == '\v'
		|| str[i] == '\f'
		|| str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	if (str[i] == '+' || str[i] == '-')
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
		res = res * 10 + (str[i++] - 48);
	return (res * sign);
}

long	ft_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}

void	ft_usleep(useconds_t time)
{
	long	t_time;

	t_time = ft_time();
	while (ft_time() - t_time < time)
		usleep(300);
}

void	thread_print(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->args->print);
	printf("%ld philo %d %s\n", ft_time() - philo->start, philo->id + 1, str);
	pthread_mutex_unlock(&philo->args->print);
}

void	clean_up(t_philo *philo)
{
	int	i;

	pthread_mutex_unlock(&philo->args->main);
	pthread_mutex_unlock(&philo->args->death);
	pthread_mutex_destroy(&philo->args->death);
	pthread_mutex_destroy(&philo->args->main);
	pthread_mutex_destroy(&philo->args->print);
	i = -1;
	while (++i < philo->args->num)
		pthread_mutex_destroy(&philo->args->fork[i]);
	free(philo->args->fork);
	free(philo->args);
}
