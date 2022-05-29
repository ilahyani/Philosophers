/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilahyani <ilahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:45:29 by ilahyani          #+#    #+#             */
/*   Updated: 2022/05/29 19:46:32 by ilahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	ft_atoi(char *str)
{
	int			i;
	long long	res;
	int			sign;

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
		if (str[i++] == '-')
			sign *= -1;
	if (str[i] == '+' || str[i] == '-')
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
		res = res * 10 + (str[i++] - 48);
	return (res * sign);
}

void	ft_usleep(long time)
{
	long	t_time;

	t_time = ft_time();
	usleep(time * 0.8 * 1000);
	while (ft_time() - t_time < time)
		usleep(50);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	thread_print(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->args->print);
	printf("%ld %d %s\n", ft_time() - philo->start, philo->id + 1, str);
	if (ft_strcmp(str, "died"))
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
