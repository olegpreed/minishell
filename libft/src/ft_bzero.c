/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 17:52:10 by preed             #+#    #+#             */
/*   Updated: 2022/03/22 20:43:34 by preed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

// puts '\0' in the first n bytes in s string
void	ft_bzero(void *s, size_t n)
{
	while (n)
		((char *)s)[--n] = '\0';
	return ;
}
//bzero does not have null pointer protection for s 