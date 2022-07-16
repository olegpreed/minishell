/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 21:32:02 by preed             #+#    #+#             */
/*   Updated: 2022/03/28 18:34:17 by preed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// applies (*del) to the content of every structure
// frees that structure
// does this for every element of the linked list
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*dbl;

	if (!*lst || !*del || !lst)
		return ;
	dbl = (*lst)->next;
	while (*lst)
	{
		ft_lstdelone(*lst, (*del));
		*lst = dbl;
		if (!dbl)
			return ;
		dbl = (*lst)->next;
	}
}
