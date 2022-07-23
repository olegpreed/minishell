/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarrosh <lgarrosh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 16:05:50 by lgarrosh          #+#    #+#             */
/*   Updated: 2022/07/23 16:20:37 by lgarrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_ll_elem	*_new_ll_elem(void *key, void *val)
{
	t_ll_elem	*elem;

	elem = (t_ll_elem *)malloc(sizeof(t_ll_elem));
	if (!elem)
		return (NULL);
	elem->key = key;
	elem->val = val;
	elem->next = NULL;
	return (elem);
}

int	llist_addend(t_llist *list, void *key, void *val)
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

int	llist_str_kcmp(const void *k1, const void *k2)
{
	return (ft_strncmp((const char *)k1, (const char *)k2, 1000));
}
