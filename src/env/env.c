/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarrosh <lgarrosh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 16:02:33 by lgarrosh          #+#    #+#             */
/*   Updated: 2022/07/21 16:25:22 by lgarrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_ll_elem	*_new_ll_elem(void *key, void *val)
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

int	ft_parse_envp(t_llist *l, char *envp[])
{
	char			*key;
	char			*val;
	unsigned int	i;

	if (!envp || !*envp || !l)
		return (-1);
	i = 0;
	while (envp[i])
	{
		if (ft_strslice(envp[i], "=", &key, &val))
			return (ft_error(1, "minishell: ft_parse_envp"));
		if (llist_addend(l, key, val))
			return (ft_error(1, "minishell: ft_parse_envp"));
		++i;
	}
	return (0);
}