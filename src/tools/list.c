/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarrosh <lgarrosh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 17:03:14 by lgarrosh          #+#    #+#             */
/*   Updated: 2022/07/23 16:18:41 by lgarrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	_llist_destroy_elem(t_llist *list, t_ll_elem *elem, t_ll_elem *prev)
{
	if (prev)
		prev->next = elem->next;
	else
		list->head = elem->next;
	if (NULL != list->key_dstr)
		list->key_dstr(elem->key);
	if (NULL != list->val_dstr)
		list->val_dstr(elem->val);
	free(elem);
	--(list->size);
}

int	llist_push(t_llist *list, void *key, void *val)
{
	t_ll_elem	*ptr;

	if (!list)
		return (1);
	if (!list->head)
	{
		list->head = _new_ll_elem(key, val);
		if (list->head)
			++(list->size);
		return (list->head == NULL);
	}
	ptr = list->head;
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = _new_ll_elem(key, val);
	if (ptr->next)
		++(list->size);
	return (ptr->next == NULL);
}

int	llist_set(t_llist *list, void *key, void *new_val)
{
	t_ll_elem	*ptr;

	if (!list)
		return (1);
	if (list->size == 0)
		return (llist_push(list, key, new_val));
	ptr = list->head;
	while (1)
	{
		if (list->key_cmpr(key, ptr->key) == 0)
		{
			if (NULL != list->val_dstr)
				list->val_dstr(ptr->val);
			ptr->val = new_val;
			return (0);
		}
		if (ptr->next)
			ptr = ptr->next;
		else
			break ;
	}
	ptr->next = _new_ll_elem(key, new_val);
	if (ptr->next)
		++(list->size);
	return (ptr->next == NULL);
}

int	llist_del(t_llist *list, const void *key)
{
	t_ll_elem	*ptr;
	t_ll_elem	*prev;

	if (!list)
		return (1);
	if (list->size == 0)
		return (0);
	ptr = list->head;
	prev = NULL;
	while (ptr)
	{
		if (list->key_cmpr(key, ptr->key) == 0)
		{
			_llist_destroy_elem(list, ptr, prev);
			return (0);
		}
		prev = ptr;
		ptr = ptr->next;
	}
	return (0);
}
