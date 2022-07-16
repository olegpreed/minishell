/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 16:22:30 by preed             #+#    #+#             */
/*   Updated: 2022/03/23 16:31:41 by preed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// finds the first c symbol in string s
// c can be '\0'. returns its address
char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c && *s != '\0')
		s++;
	if (((char)c == '\0' && *s == '\0') || *s != '\0')
		return ((char *)s);
	return (0);
}
