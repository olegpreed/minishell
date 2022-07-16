/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 19:38:05 by preed             #+#    #+#             */
/*   Updated: 2022/03/23 18:58:11 by preed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// allocates memory in heap and zeroes it out
void	*ft_calloc(size_t count, size_t size)
{
	void	*a;

	a = (char *)malloc(size * count);
	if (a == 0)
		return (NULL);
	ft_bzero(a, size * count);
	return (a);
}
