/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarrosh <lgarrosh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:24:18 by lgarrosh          #+#    #+#             */
/*   Updated: 2022/07/23 13:18:54 by lgarrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_llist	*llist_new(t_llist_key_comparator_ptr key_cmpr,
			t_llist_key_destructor_ptr key_dstr,
			t_llist_val_destructor_ptr val_dstr)
{
	t_llist	*list;

	list = (t_llist *)malloc(sizeof(t_llist));
	if (!list)
		return (NULL);
	list->head = NULL;
	list->key_cmpr = key_cmpr;
	list->key_dstr = key_dstr;
	list->val_dstr = val_dstr;
	list->size = 0;
	return (list);
}

static void	_ft_init_builtins(t_info *info)
{
	info->reserved_words[0] = "echo";
	info->reserved_words[1] = "cd";
	info->reserved_words[2] = "pwd";
	info->reserved_words[3] = "export";
	info->reserved_words[4] = "unset";
	info->reserved_words[5] = "env";
	info->reserved_words[6] = "exit";
	// info->f_ptrs[0] = &ft_echo;
	// info->f_ptrs[1] = &ft_cd;
	info->f_ptrs[2] = &ft_pwd;
	// info->f_ptrs[3] = &ft_export;
	info->f_ptrs[4] = &ft_unset;
	info->f_ptrs[5] = &ft_env;
	// info->f_ptrs[6] = &ft_exit;
}

int	ft_init(t_info *info, char *envp[])
{
	signal(SIGQUIT, SIG_IGN);
	g_exit = 0;
	info->envp_f = 1;
	info->exit_f = 1;
	info->g_exit_str = NULL;
	info->envp = NULL;
	info->envp_list = llist_new(llist_str_kcmp, free, free);
	if (info->envp_list == NULL)
		return (ft_error(1, "minishell: ft_init"));
	if (ft_parse_envp(info->envp_list, envp))
		return (1);
	_ft_init_builtins(info);
	return (0);
}