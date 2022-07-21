/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarrosh <lgarrosh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:24:18 by lgarrosh          #+#    #+#             */
/*   Updated: 2022/07/21 15:24:34 by lgarrosh         ###   ########.fr       */
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