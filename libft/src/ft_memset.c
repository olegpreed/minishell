/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 17:46:52 by preed             #+#    #+#             */
/*   Updated: 2022/03/22 20:43:54 by preed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

// changes the first len symbols to c
void	*ft_memset(void *b, int c, size_t len)
{
	while (len)
		((unsigned char *)b)[--len] = c;
	return (b);
}
//memset does not have null pointer protection for s 