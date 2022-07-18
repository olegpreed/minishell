/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarrosh <lgarrosh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:02:42 by lgarrosh          #+#    #+#             */
/*   Updated: 2022/07/18 17:07:00 by lgarrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handler(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_redisplay();
	rl_replace_line("", 1);
	rl_redisplay();
}

char	*ft_readline(char *prom)
{
	char	*line;

	line = readline(prom);
	if (line)
		add_history(line);
	return (line);
}
