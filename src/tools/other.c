/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarrosh <lgarrosh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 16:20:45 by lgarrosh          #+#    #+#             */
/*   Updated: 2022/07/21 16:26:14 by lgarrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strcpy(const char *s)
{
	char		*copy;
	const int	length = ft_strlen(s);
	int			i;

	if (!s)
		return (NULL);
	copy = (char *)malloc(sizeof(char) * (length + 1));
	if (copy)
	{
		i = length;
		copy[length] = '\0';
		while (i--)
			copy[i] = s[i];
	}
	return (copy);
}

int	ft_strcontains(const char *s, const char c)
{
	if (s)
	{
		while (*s && *s != c)
			++s;
		if (*s == c)
			return (1);
	}
	return (0);
}

int	ft_strslice(const char *s, const char *delim, char **a, char **b)
{
	int		j;
	int		i;

	if (!s || !delim)
		return (-1);
	j = 0;
	while (s[j] && !ft_strcontains(delim, s[j]))
		++j;
	i = j;
	*a = (char *)malloc(sizeof(char) * (j + 1));
	if (!a)
		return (1);
	while (i--)
		(*a)[i] = s[i];
	(*a)[j] = '\0';
	if (s[j] == '\0')
		*b = NULL;
	else
		*b = ft_strcpy(s + j + 1);
	if (b)
		return (0);
	free(*a);
	return (1);
}