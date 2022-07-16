/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 19:52:32 by preed             #+#    #+#             */
/*   Updated: 2022/03/23 19:19:33 by preed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*happyend(char *s1cpy, char *set, int i)
{
	while (set[i])
	{
		if (ft_strchr(s1cpy, set[i]) == s1cpy)
		{
			s1cpy--;
			i = 0;
		}
		else
			i++;
	}
	return (s1cpy);
}

// creates in heap an altered version of a string s1
// where all the symbols from the SET have been deleted
// from the beginning and from the end of the string
char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	char	*s1end;
	char	*a;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	s1end = (char *)s1 + ft_strlen(s1) - 1;
	while (set[i])
	{
		if (ft_strchr(s1, set[i]) == s1)
		{
			s1++;
			i = 0;
		}
		else
			i++;
	}
	i = 0;
	s1end = happyend(s1end, (char *)set, i);
	a = ft_substr(s1, 0, s1end - s1 + 1);
	return (a);
}
