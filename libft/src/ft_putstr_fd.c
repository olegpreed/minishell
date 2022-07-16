/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 14:06:30 by preed             #+#    #+#             */
/*   Updated: 2022/03/28 18:12:04 by preed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// Outputs the string ’s’ to the given file descriptor
void	ft_putstr_fd(char *s, int fd)
{
	if (s)
	{
		while (*s)
		{
			write(fd, s, 1);
			s++;
		}
	}
}
