/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:49:54 by preed             #+#    #+#             */
/*   Updated: 2022/03/28 18:10:52 by preed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// applies function (*f) to every element of s
// returns the altered string allocated in heap
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*e;
	int		l;

	if (!s || !*f)
		return (0);
	l = ft_strlen(s);
	e = (char *)ft_calloc(l + 1, sizeof(char));
	if (e == 0)
		return (0);
	while (l--)
		e[l] = (*f)(l, s[l]);
	return (e);
}
