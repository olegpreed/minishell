/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 19:01:07 by preed             #+#    #+#             */
/*   Updated: 2022/03/23 19:06:13 by preed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// joins together s1 and s2 and copies the result to the heap
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*a;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	a = (char *)ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (a == NULL)
		return (NULL);
	ft_strlcpy(a, s1, ft_strlen(s1) + 1);
	ft_strlcat(a, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	return (a);
}
