/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 16:22:30 by preed             #+#    #+#             */
/*   Updated: 2022/03/23 18:25:50 by preed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

// compares the first different symbol in s1 and s2
// compares not more than n bytes and not after '\0'
// if all symbols are same in that range, returns 0;
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < (n - 1) && (s1[i] == s2[i]) && (s1[i] != '\0' || s2[i] != '\0'))
		i++;
	if ((unsigned char)s1[i] > (unsigned char)s2[i])
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	if ((unsigned char)s1[i] < (unsigned char)s2[i])
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	else
		return (0);
}
