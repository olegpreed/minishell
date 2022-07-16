/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 16:22:30 by preed             #+#    #+#             */
/*   Updated: 2022/03/23 18:31:21 by preed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

// same as strchr except it doesn't stop after '/0'
// searches not more than n bytes
// (hence the name - MEMchr )
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*a;

	if (n == 0)
		return (0);
	a = (unsigned char *)s;
	while (n--)
	{
		if (*a != (unsigned char) c)
			a++;
		else
			return (a);
	}
	return (0);
}
