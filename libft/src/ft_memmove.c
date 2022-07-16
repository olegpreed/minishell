/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 17:54:18 by preed             #+#    #+#             */
/*   Updated: 2022/03/23 19:31:09 by preed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// copies n bytes from src to dst (does not ovewrite the dst)
//   char a[] = "dst";      │ ········dst····· │
//   char b[] = "src";		│ ····src·dst····· │
//   memmove(a , b, 6);     │ ····src·src·ds·· │
void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	if ((dst == NULL && src == NULL) || (size_t)ft_strlen(dst) < n)
		return (0);
	d = dst;
	s = (unsigned char *)src;
	i = 0;
	if (s < d)
		while (n--)
			d[n] = s[n];
	else
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (d);
}
