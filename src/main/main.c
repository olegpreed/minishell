/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarrosh <lgarrosh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 12:31:06 by lgarrosh          #+#    #+#             */
/*   Updated: 2022/07/23 13:20:23 by lgarrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	_main_pre(t_llist **tokens, char **line, char *argv[], int argc)
// {
// 	(void)argv;
// 	(void)argc;
// 	signal(SIGINT, handler);
// 	errno = 0;
// 	*tokens = llist_new(llist_int_kcmp, NULL, free);
// 	*line = _ft_readline(MINIS_PROMPT);
// }

// void	_main_post(t_llist *tokens)
// {
// 	llist_free(tokens);
// 	signal(SIGQUIT, SIG_IGN);
// }

int	main(int argc, char **argv, char **envp)
{
	t_info		info;
	char		*line;

	(void)argc;
	(void)argv;
	line = NULL;
	ft_init(&info, envp);
	signal(SIGINT, handler);
	while (info.exit_f)
	{
		//_main_pre
		line = ft_readline(PROM);
		if (!line)
			info.exit_f = 0;
		//_main_post
	}
	write(1, "exiting...\n", 11);
	ft_env(info.envp_list, &info);
	//destroy
	return (0);
}