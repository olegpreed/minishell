/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 17:54:18 by preed             #+#    #+#             */
/*   Updated: 2022/03/23 19:28:46 by preed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// copies n bytes from src to dst (overwriting the dst)
//   char a[] = "destiny";  │ ········destiny· │
//   char b[] = "src";		│ ····src·destiny· │
//   memcpy(a , b, 6);      │ ····src·src·src· │
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if ((dst == NULL && src == NULL) || (size_t)ft_strlen(dst) < n)
		return (0);
	while (i < n)
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
	}
	return (dst);
}
// dst length must be larger than n