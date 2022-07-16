/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 16:22:30 by preed             #+#    #+#             */
/*   Updated: 2022/03/23 18:18:09 by preed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// returns the address of the last symbol c
// found in the string
char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (s[i] != (char)c && i > 0)
		i--;
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (0);
}
