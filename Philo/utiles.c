/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilahyani <ilahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 11:13:03 by ilahyani          #+#    #+#             */
/*   Updated: 2022/05/17 18:01:53 by ilahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error_check(int argc, char** argv)
{
	int	i;

	i = 1;
	if (argc != 5 && argc != 6)
		return (1);
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

void	*routine(void *args)
{
	//eat()
	//sleep()
	//think()
	(void) args;
	eat(args);
	printf("philo born o_o\n");
	sleep(2);
	printf("philo dead x_x\n");
	return (NULL);
}

int	philo_create(t_args *args)
{
	int	i;

	i = 0;
	while (i < args->num)
		if ((pthread_create(&args->philo[i++].ph, NULL, &routine, args)) != 0)
			return (1);
	return (0);
}

pthread_mutex_t	*get_args(t_args *args, char **av)
{
	pthread_mutex_t	*forks;
	int	i;

	args->num = ft_atoi(av[1]);
	args->t_die = ft_atoi(av[2]);
	args->t_eat = ft_atoi(av[3]);
	args->t_sleep = ft_atoi(av[4]);
	if (av[5])
		args->n_eat = ft_atoi(av[5]);
	forks = malloc(sizeof(forks) * args->num);
	args->philo = malloc(sizeof(args->philo) * args->num);
	i = 0;
	while (i < args->num)
	{
		args->philo[i].id = i;
		args->philo[i].right_fork = i;
		args->philo[i].left_fork = (i + 1) % args->num;
		i++;
	}
	return (forks);
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
