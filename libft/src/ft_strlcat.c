/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleg <oleg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 21:14:50 by preed             #+#    #+#             */
/*   Updated: 2022/07/11 17:36:42 by oleg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// adds (dstsize - strlen(dst) - 1) characters 
// to the end of dst from src.  '\0' in the end
size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len_src;
	size_t	i;
	size_t	j;

	len_src = ft_strlen(src);
	i = 0;
	j = 0;
	if (size == 0)
		return (len_src);
	while (dest[i] != '\0' && i < size)
		i++;
	while (src[j] && ((i + j) < (size - 1)))
	{
		dest[i + j] = src[j];
		j++;
	}
	if (i + j < size)
		dest[i + j] = '\0';
	return (len_src + i);
}

//	weird strlcat behavior:	
//  char a[] = "Jennifer ";
//	char b[] = "Affleck";			 │ ······Affleck·Je │
//									 │ nnifer ········· │
//	strlcat(a, b, 17);				 │ ······Affleck·Je │
//									 │ nnifer ········· │
//
//	char a[] = "Jennifer \0Lopez\0";
//	char b[] = "Affleck";			 │ ········Affleck· │
//									 │ Jennifer ·Lopez· │
//	strlcat(a, b, 17);				 │ ········Affleck· │
//									 │ Jennifer Affleck │
