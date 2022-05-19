/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilahyani <ilahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 11:13:03 by ilahyani          #+#    #+#             */
/*   Updated: 2022/05/19 17:24:47 by ilahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

int	ft_perror(char *str) 		//Print error and free memory
{
	int	i;

	if (!str)
		str = "(null)";
	i = 0;
	while (str[i])
		write(2, &str[i++], 1);
	return (1);
}

void	*routine(void *philo)
{
	t_philo *p;
	
	p = (t_philo *)philo;
	while (1)
		eat(p);
	return (NULL);
}

int	philo_create(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->args.num)
		if ((pthread_create(&philo[i].ph, NULL, &routine, &philo[i])) != 0)
			return (1);
	i = 0;
	while (i < philo->args.num)
		if ((pthread_detach(philo[i++].ph)) != 0)
			return (1);
	return (0);
}

t_philo	*get_args(char **av)
{
	t_philo *philo;
	int	i;

	philo = (t_philo *)malloc(sizeof(t_philo) * ft_atoi(av[1]));
	philo->args.num = ft_atoi(av[1]);
	philo->args.t_die = ft_atoi(av[2]);
	philo->args.t_eat = ft_atoi(av[3]);
	philo->args.t_sleep = ft_atoi(av[4]);
	if (av[5])
		philo->args.n_eat = ft_atoi(av[5]);
	i = 0;
	while (i < philo->args.num)
	{
		philo[i].id = i;
		philo[i].right_fork = i;
		philo[i].left_fork = (i + 1) % philo->args.num;
		philo[i].args.forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
		i++;
	}
	return (philo);
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
