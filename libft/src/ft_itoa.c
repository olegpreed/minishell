/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 19:12:43 by preed             #+#    #+#             */
/*   Updated: 2022/03/28 18:10:32 by preed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*final(char *a, int j, int n, int k)
{
	while (n > 0)
	{
		a[j] = n % 10 + 48;
		n = n / 10;
		j--;
	}
	if (k == -1 || k == 0)
	{
		a[j] = '-';
		if (k == 0)
			a[ft_strlen(a) - 1] = '8';
		return (&a[j]);
	}
	return (&a[j + 1]);
}

static int	count(int n)
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

static int	cases(int n, int *p)
{
	if (n < 0)
	{
		*p = -1;
		if (n == -2147483648)
		{
			*p = 0;
			return (2147483647);
		}
		else
			return (-n);
	}
	return (n);
}

static char	*nolik(void)
{
	char	*a;

	a = (char *)ft_calloc(2, sizeof(char));
	if (a == 0)
		return (0);
	a[0] = '0';
	return (a);
}

// turns int into a string
char	*ft_itoa(int n)
{
	char	*a;
	int		j;
	int		k;
	int		*p;

	k = 1;
	p = &k;
	if (n == 0)
		return (nolik());
	n = cases(n, p);
	j = count(n);
	if (k == -1 || k == 0)
		a = (char *)ft_calloc(j + 2, sizeof(char));
	else
	{
		a = (char *)ft_calloc(j + 1, sizeof(char));
		j--;
	}
	if (a == 0)
		return (0);
	return (final(a, j, n, k));
}
