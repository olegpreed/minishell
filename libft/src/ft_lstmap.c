/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 22:15:15 by preed             #+#    #+#             */
/*   Updated: 2022/03/28 18:34:38 by preed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_iter(t_list *lst, void *(*f)(void *))
{
	while (lst)
	{
		lst->content = (*f)(lst->content);
		lst = lst->next;
	}
}

// creates a copy of linked list in heap
// applies (*f) to the content of every structure
// (*del) is applied to content if malloc failed to allocate memory
// every structure created before is freed in that case 
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*a;
	t_list	*hold;
	t_list	**holst;

	a = (t_list *)malloc(sizeof(t_list));
	if (!a || !lst)
		return (0);
	hold = a;
	holst = &hold;
	a->content = lst->content;
	while (lst->next)
	{
		a->next = (t_list *)malloc(sizeof(t_list));
		if (!(a->next))
		{
			ft_lstclear(holst, (*del));
			return (0);
		}
		lst = lst->next;
		(a->next)->content = lst->content;
		a = a->next;
	}
	a->next = 0;
	ft_iter(hold, (*f));
	return (hold);
}
