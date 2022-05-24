/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilahyani <ilahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 11:13:03 by ilahyani          #+#    #+#             */
/*   Updated: 2022/05/24 11:11:43 by ilahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->args->fork[philo->right_fork]);
	thread_print(philo, "picked up the right fork");
	if (philo->left_fork != -1)
	{
		pthread_mutex_lock(&philo->args->fork[philo->left_fork]);
		thread_print(philo, "picked up the left fork");
		thread_print(philo, "is eating...");
		usleep(philo->args->t_eat * 1000);
		philo->last_meal = ft_time();
		(philo->meals)++;
		printf("%d had taken %d meals\n", philo->id, philo->meals);
		pthread_mutex_unlock(&philo->args->fork[philo->left_fork]);
		pthread_mutex_unlock(&philo->args->fork[philo->right_fork]);
		return (1);
	}
	philo->last_meal = 0;
	return (0);
}

void	*routine(void *philo)
{
	t_philo	*p;
	int		i;

	p = (t_philo *)philo;
	while (1)
	{
		i = -1;
		if (p->id % 2 == 0)
			while (++i < 5)
				usleep(20);
		if (eat(p))
		{
			thread_print(philo, "is sleeping...");
			usleep(p->args->t_sleep * 1000);
			thread_print(philo, "is thinking...");
		}
	}
	return (NULL);
}

void	*kill_thread(void *philo)
{
	t_philo	*p;
	int		i;

	p = (t_philo *)philo;
	while (1)
	{
		if (ft_time() - p->last_meal >= p->args->t_die)
		{
			pthread_mutex_lock(&p->args->death);
			thread_print(philo, "died");
			pthread_mutex_lock(&p->args->print);
			pthread_mutex_unlock(&p->args->main);
			return (NULL);
		}
		i = -1;
		while (++i < p->args->num)
			if ((p + i)->meals < p->args->num_of_meals)
				break ;
		if (i == p->args->num)
		{
			pthread_mutex_lock(&p->args->print);
			pthread_mutex_unlock(&p->args->main);
			return (NULL);
		}
	}
}

int	philo_create(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->args->num)
	{
		philo[i].start = ft_time();
		if ((pthread_create(&philo[i].ph, NULL, &routine, &philo[i])) != 0)
			return (1);
	}
	i = -1;
	while (++i < philo->args->num)
		if ((pthread_detach(philo[i].ph) != 0))
			return (1);
	return (0);
}

t_philo	*get_args(char **av)
{
	t_philo *philo;
	t_args	*args;
	int	i;

	philo = (t_philo *)malloc(sizeof(t_philo) * ft_atoi(av[1]));
	if (!philo)
		return (NULL);
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
	for (int i = 0; i < args->num; i++)
		pthread_mutex_init(&args->fork[i], NULL);
	i = -1;
	while (++i < ft_atoi(av[1]))
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

void	thread_print (t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->args->print);
	printf("%ld philo %d %s\n", ft_time() - philo->start, philo->id + 1, str);
	pthread_mutex_unlock(&philo->args->print);
}

long	ft_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}

int	ft_atoi(char *str)
{
	int			i;
	int			res;
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

int	is_int(char* c)
{
	int	i;
	
	i = 0;
	while (c[i])
		{
			if (c[i] < '0' || c[i] > '9')
				return (0);
			i++;
		}
	return (1);
}

int	error_check(int argc, char** argv)
{
	int	i;

	if (argc != 5 && argc != 6)
		return (1);
	i = 1;
	while (i < argc)
		if(!is_int(argv[i++]))
			return (1);
	return (0);
}
