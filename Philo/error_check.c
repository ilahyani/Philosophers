/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilahyani <ilahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 17:04:02 by ilahyani          #+#    #+#             */
/*   Updated: 2022/05/29 10:55:17 by ilahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

	if ((argc != 5 && argc != 6))
		return (1);
	i = 0;
	while (++i < argc)
		if (ft_atoi(argv[i]) < 1 || ft_atoi(argv[i]) > 2147483647)
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
