/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 22:08:05 by preed             #+#    #+#             */
/*   Updated: 2022/03/28 18:34:27 by preed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// applies (*f) to the content of every element of linked list
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !*f)
		return ;
	while (lst)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}
