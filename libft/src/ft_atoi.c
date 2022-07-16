/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 18:01:10 by preed             #+#    #+#             */
/*   Updated: 2022/03/23 19:11:51 by preed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putnbr(const char *str, int i, int e)
{
	long long int	num;

	num = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (num > (9223372036854775807 - (long long)((str[i]) - 48)) / 10)
			return (-2);
		else if (num == 922337203685477580 && (str[i] - 48) == 7 && e == -1)
			return (-1);
		num = 10 * num + (str[i] - 48);
		i++;
	}
	return ((int)num);
}

// turns a string into an int
// INT_MAX < number <= LLONG_MAX 	overflow
// LLONG_MAX < number				-1
// number < LLONG_MIN				0
int	ft_atoi(const char *str)
{
	int	i;
	int	e;
	int	k;

	i = 0;
	e = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		e *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	else if (str[i] < '0' || str[i] > '9')
		return (0);
	k = ft_putnbr(str, i, e);
	if (k == -2 && e == -1)
		return (0);
	else if (k == -2 && e == 1)
		return (-1);
	return (k * e);
}
