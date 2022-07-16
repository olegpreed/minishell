/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 14:06:30 by preed             #+#    #+#             */
/*   Updated: 2022/03/28 18:11:37 by preed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// Outputs the character ’c’ to the given file descriptor
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
