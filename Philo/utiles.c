/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilahyani <ilahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 11:13:03 by ilahyani          #+#    #+#             */
/*   Updated: 2022/05/22 10:51:22 by ilahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->args.forks[philo->right_fork]);
	thread_print(philo, "picked up the right fork");
	if (philo->left_fork != -1)
	{
		pthread_mutex_lock(&philo->args.forks[philo->left_fork]);
		thread_print(philo, "picked up the left fork");
		thread_print(philo, "is eating...");
		philo->last_meal = ft_time() - philo->start;
		usleep(philo->args.t_eat * 1000);
		pthread_mutex_unlock(&philo->args.forks[philo->right_fork]);
		pthread_mutex_unlock(&philo->args.forks[philo->left_fork]);
		return (1);
	}
	philo->last_meal = 0;
	return (0);
}

void	*routine(void *philo)
{
	t_philo 		*p;
	t_args			a;
	pthread_t		death_check;

	p = (t_philo *)philo;
	a = p->args;
	if ((pthread_create(&death_check, NULL, &is_dead, philo)) != 0)
		return (NULL);
	if ((pthread_detach(death_check)) != 0)
		return (NULL);
	while (1)
	{
		if (eat(p))
		{
			thread_print(philo, "is thinking...");
			thread_print(philo, "is sleeping...");
			usleep(p->args.t_sleep * 1000);
		}
		// if ((ft_time() - p->start) - p->last_meal > a.t_die)
		// {
		// 		pthread_mutex_lock(&p->args.death);
		// 		pthread_mutex_unlock(&p->args.main);
		// 		thread_print(philo, "is dead");
		// 		return (NULL);
		// }
		// usleep(10000);
	}
	return (NULL);
}

void	*is_dead(void *philo)
{
	t_philo	*p;

	p = (t_philo *)philo;
	//pthread_mutex_lock(&p->args.death);
	while (1)
	{
		if (p->last_meal != -1 && ft_time() - p->last_meal >= p->args.t_die)
		{
			//p->is_dead = 1;
			thread_print(philo, "is dead");
			pthread_mutex_unlock(&p->args.main);
			return (NULL);
		}
	}
}

int	philo_create(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->args.num)
		if ((pthread_create(&philo[i].ph, NULL, &routine, &philo[i])) != 0)
			return (1);
	i = -1;
	while (++i < philo->args.num)
		if ((pthread_detach(philo[i].ph) != 0))
			return (1);
	return (0);
}

t_philo	*get_args(char **av)
{
	t_philo *philo;
	int	i;

	philo = (t_philo *)malloc(sizeof(t_philo) * ft_atoi(av[1]));
	if (!philo)
		return (NULL);
	philo->args.num = ft_atoi(av[1]);
	philo->args.t_die = ft_atoi(av[2]);
	philo->args.t_eat = ft_atoi(av[3]);
	philo->args.t_sleep = ft_atoi(av[4]);
	if (av[5])
		philo->args.n_eat = ft_atoi(av[5]);
	i = -1;
	while (++i < philo->args.num)
	{
		philo[i].id = i;
		philo[i].right_fork = i;
		philo[i].start = ft_time();
		philo[i].left_fork = (i + 1) % philo->args.num;
		if (philo->args.num < 2)
			philo[i].left_fork = -1;
		philo[i].last_meal = -1;
		philo[i].is_dead = 0;
		philo[i].args.forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
		if (!philo[i].args.forks)
			return (NULL);
		pthread_mutex_init(&philo->args.forks[i], NULL);
	}
	return (philo);
}

void	thread_print (t_philo *philo, char *str)
{
	// if (philo->is_dead)
	// 	return ;
	pthread_mutex_lock(&philo->args.print);
	printf("%ld philo %d %s\n", ft_time() - philo->start, philo->id + 1, str);
	pthread_mutex_unlock(&philo->args.print);
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
