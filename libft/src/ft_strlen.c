/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 17:43:40 by preed             #+#    #+#             */
/*   Updated: 2022/07/18 16:09:02 by lgarrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//counts symbols in line
//does not count the last null-terminating character
int	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}
