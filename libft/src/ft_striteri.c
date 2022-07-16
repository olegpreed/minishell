/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 13:51:25 by preed             #+#    #+#             */
/*   Updated: 2022/03/28 18:11:18 by preed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// applies function (*f) to every element of a string s.
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int		l;

	if (!*f)
		return ;
	if (s != 0)
	{
		l = ft_strlen(s);
		while (l--)
			(*f)(l, &s[l]);
	}
}
