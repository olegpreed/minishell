/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 14:30:47 by preed             #+#    #+#             */
/*   Updated: 2022/03/28 18:12:34 by preed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int	step(int a)
{
	long int	res;
	int			i;

	i = 0;
	res = 10;
	while (i < a - 1)
	{
		res = 10 * res;
		i++;
	}
	return (res);
}

static int	count(long int n)
{
	int	j;

	j = 0;
	while (n > 0)
	{
		n = n / 10;
		j++;
	}
	return (j);
}

// Outputs the integer ’n’ to the given file descriptor
void	ft_putnbr_fd(int n, int fd)
{
	int			j;
	char		c;
	long int	p;

	p = n;
	if (!p)
	{
		ft_putchar_fd(48, fd);
		return ;
	}
	if (p < 0)
	{
		p = -p;
		ft_putchar_fd('-', fd);
	}
	j = count(p);
	while (j)
	{
		if (j == 1)
			c = p % step(j) + 48;
		else
			c = p % step(j) / step(j - 1) + 48;
		j--;
		ft_putchar_fd(c, fd);
	}
}
