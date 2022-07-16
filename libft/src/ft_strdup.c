/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 20:28:42 by preed             #+#    #+#             */
/*   Updated: 2022/03/23 19:01:02 by preed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// copies s1 to heap. returns the adress to it
// that can be used to free the allocated memory
char	*ft_strdup(const char *s1)
{
	char	*a;
	char	*b;

	a = (char *)malloc(ft_strlen(s1) + 1);
	b = a;
	if (a == 0)
		return (NULL);
	while (*s1)
	{
		*a = *s1;
		a++;
		s1++;
	}
	*a = *s1;
	return (b);
}
