/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 16:22:30 by preed             #+#    #+#             */
/*   Updated: 2022/03/23 18:31:53 by preed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

//	char a[] = "Do\0 We look the same?";
//	char b[] = "Do\0 we look the same?";
//	printf("%d", memcmp(a, b, 11));				-32
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (n == 0)
		return (0);
	while ((n - 1) && *(const char *)s1 == *(const char *)s2)
	{
		n--;
		s1++;
		s2++;
	}
	if ((n - 1) == 0 && *(const char *)s1 == *(const char *)s2)
		return (0);
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
