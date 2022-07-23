/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarrosh <lgarrosh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 15:21:37 by lgarrosh          #+#    #+#             */
/*   Updated: 2022/07/23 16:09:29 by lgarrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd(t_llist *args, t_info *info)
{
	char			pwd[PATH_MAX];
	unsigned int	i;

	(void)info;
	(void)args;
	g_exit = 0;
	if (getcwd(pwd, PATH_MAX) == NULL)
		return (ft_error(-1, "minishell: pwd: getcwd"));
	i = 0;
	while (i < PATH_MAX && pwd[i])
		++i;
	if (i < PATH_MAX)
		pwd[i++] = '\n';
	if (write(STDOUT_FILENO, pwd, i) == -1)
		return (ft_error(-1, "minishell: pwd: write"));
	return (0);
}

int	ft_env(t_llist *args, t_info *info)
{
	t_ll_elem	*ptr;

	(void)args;
	g_exit = 0;
	ptr = info->envp_list->head;
	while (ptr)
	{
		if (write(STDOUT_FILENO, ptr->key, ft_strlen((char *)ptr->key)) == -1)
			return (ft_error(-1, "minishell: env: write"));
		if (write(STDOUT_FILENO, "=", 1) == -1)
			return (ft_error(-1, "minishell: env: write"));
		if (write(STDOUT_FILENO, ptr->val, ft_strlen((char *)ptr->val)) == -1)
			return (ft_error(-1, "minishell: env: write"));
		if (write(STDOUT_FILENO, "\n", 1) == -1)
			return (ft_error(-1, "minishell: env: write"));
		ptr = ptr->next;
	}
	return (0);
}

int	ft_unset(t_llist *args, t_info *info)
{
	t_ll_elem	*arg;

	g_exit = 0;
	arg = args->head;
	if (arg->next)
	{
		arg = arg->next;
		while (arg)
		{
			if (ft_is_valid_id(arg->val))
				llist_del(info->envp_list, arg->val);
			else
			{
				g_exit = 1;
				write(STDERR_FILENO, "minishell: unset: not valid\n", 29);
			}
			arg = arg->next;
		}
	}
	info->envp_f = 1;
	return (0);
}

void	not_valid_handler(char *a, char *b)
{
	g_exit = 1;
	free(a);
	free(b);
	write(STDERR_FILENO, "minishell: export: not valid\n", 30);
}
