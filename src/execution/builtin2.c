/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarrosh <lgarrosh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 16:08:14 by lgarrosh          #+#    #+#             */
/*   Updated: 2022/07/23 16:09:22 by lgarrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_export_print(t_info *info)
{
	t_ll_elem	*ptr;

	ptr = info->envp_list->head;
	while (ptr)
	{
		if (write(STDOUT_FILENO, "declare -x ", 11) == -1)
			return (ft_error(-1, "minishell: export: write"));
		if (write(STDOUT_FILENO, ptr->key, ft_strlen((char *)ptr->key)) == -1)
			return (ft_error(-1, "minishell: export: write"));
		if (ptr->val)
		{
			if (write(STDOUT_FILENO, "=\"", 2) == -1)
				return (ft_error(-1, "minishell: export: write"));
			if (write(STDOUT_FILENO, ptr->val,
					ft_strlen((char *)ptr->val)) == -1)
				return (ft_error(-1, "minishell: export: write"));
			if (write(STDOUT_FILENO, "\"", 2) == -1)
				return (ft_error(-1, "minishell: export: write"));
		}
		if (write(STDOUT_FILENO, "\n", 1) == -1)
			return (ft_error(-1, "minishell: export: write"));
		ptr = ptr->next;
	}
	g_exit = 0;
	return (0);
}

static int	handle_insert(t_info *info, char *a, char *b, char *val)
{
	if (ft_strcontains(val, '='))
	{
		if (llist_set(info->envp_list, a, b))
		{
			free(a);
			free(b);
			return (ft_error(-1, "minishell: export: set"));
		}
	}
	else
	{
		if (llist_set(info->envp_list, a, NULL))
		{
			free(a);
			free(b);
			return (ft_error(-1, "minishell: export: set"));
		}
		free(b);
	}
	return (0);
}

int	ft_export(t_llist *args, t_info *info)
{
	t_ll_elem	*ptr;
	char		*a;
	char		*b;

	ptr = args->head;
	if (args->size == 1)
		return (ft_export_print(info));
	ptr = ptr->next;
	g_exit = 0;
	info->envp_f = 1;
	while (ptr)
	{
		if (ft_strslice((char *)ptr->val, "=", &a, &b))
			return (ft_error(-1, "minishell: export: parse"));
		if (!ft_is_valid_id(a))
			not_valid_handler(a, b);
		else if (handle_insert(info, a, b, (char *)ptr->val))
			return (1);
		ptr = ptr->next;
	}
	return (0);
}
