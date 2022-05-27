/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilahyani <ilahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 11:13:03 by ilahyani          #+#    #+#             */
/*   Updated: 2022/05/27 17:33:16 by ilahyani         ###   ########.fr       */
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

int	is_int(char *c)
{
	int	i;

	i = -1;
	while (c[++i])
		if (c[i] < '0' || c[i] > '9')
			return (0);
	return (1);
}

int	error_check(int argc, char **argv)
{
	int	i;

	if ((argc != 5 && argc != 6) || ft_atoi(argv[1]) < 1)
		return (1);
	i = 0;
	while (++i < argc)
	{
		if (!is_int(argv[i]))
			return (1);
		if (i == 5)
			if (ft_atoi(argv[i]) < 1)
				return (1);
	}
	return (0);
}
